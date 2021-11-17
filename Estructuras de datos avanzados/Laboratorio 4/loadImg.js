let img_input = document.getElementById('input_image');
let file_input = document.getElementById('file_input');
let canvas = document.getElementById('output_image');
let canvasPalette = document.getElementById('output_palette');
let ctxCanvasPalette = canvasPalette.getContext('2d');
let ctx = canvas.getContext('2d');
let octree = new Octree();

file_input.addEventListener('change', (event) => { img_input.src = URL.createObjectURL(event.target.files[0]);}, false);

class Color {
    constructor( red, green, blue ) {
        this.red = red;
        this.green = green;
        this.blue = blue;
    }
};

img_input.onload = function() {
    let mat = cv.imread(img_input);

    let img_width = img_input.naturalWidth;
    let img_height = img_input.naturalHeight;
    ctx.rect(0, 0, img_width, img_height);

    cv.imshow('output_image', mat);

    let data = ctx.getImageData(0, 0, img_width, img_height).data;
    let matrix_image = [];

    for(let i = 0; i < data.length; i = i + 4) {
        matrix_image.push(new Color(data[i], data[i+1], data[i+2]));  
    }

    octree.fill(matrix_image);  
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reduction(octree.head);
    octree.reconstruction(matrix_image);

    console.log(octree);

    let count = 0;
    for(let i = 0; i < img_height; i++) {
        for(let j = 0; j < img_width; j++) {
            mat.ucharPtr(i, j)[0] = matrix_image[count].red;
            mat.ucharPtr(i, j)[1] = matrix_image[count].green;
            mat.ucharPtr(i, j)[2] = matrix_image[count].blue;
            count++;
        }
    }
    cv.imshow('output_image', mat);

    var matRgbPalette = [];
    octree.pallete(octree.head, matRgbPalette);
    
    let sizeMatRgb = matRgbPalette.length;
    console.log(sizeMatRgb);
    let sizePalette;
    if(sizeMatRgb <= (1 << 18)){
        sizePalette = 1 << 9;
        
    }else{
        sizePalette = 1 << 12;
    }
    console.log(sizePalette);
    let matPalette = new cv.Mat(sizePalette, sizePalette, cv.CV_8UC3);
    ctxCanvasPalette.rect(0, 0, sizePalette, sizePalette);

    let count2 = 0, temp = 0;
    let totalPixelsPerColor = Math.floor( sizePalette*sizePalette / sizeMatRgb);
    console.log(totalPixelsPerColor);
    for(let i = 0 ; i < sizePalette; ++i){
        for(let j = 0; j < sizePalette; ++j){
            if(count2 === sizeMatRgb){
                matPalette.ucharPtr(i, j)[0] = 255;
                matPalette.ucharPtr(i, j)[1] = 255;
                matPalette.ucharPtr(i, j)[2] = 255;
                continue;
            }
            matPalette.ucharPtr(i, j)[0] = matRgbPalette[count2].red;
            matPalette.ucharPtr(i, j)[1] = matRgbPalette[count2].green;
            matPalette.ucharPtr(i, j)[2] = matRgbPalette[count2].blue;

            if(temp > totalPixelsPerColor - 1){
                count2++;
                temp = 0;
            }
            temp++;
        }
    }
    
    cv.imshow('output_palette', matPalette);

    mat.delete();
}