let range;
let width = 900;
let height = 900;

let root;
let data = [];

function drawGrid(){
    for(let i = 0; i < width; i += range){
        for(let j = 0; j < height; j += range){
        stroke(0);
        strokeWeight(1);
        line(i, 0, i, height);
        line(0, j, width, j);
        }
    }
}

function drawPoints(){
    for(let i = 0; i < data.length; i++){
        let x = data[i].x;
        let y = data[i].y;
        let r = data[i].r;
        fill(255);
        noStroke();
        ellipse(x, y, r, r);
    }
}



function drawRange(){
    for(let i = 0; i < data.length; i++){
        let x = data[i].x;
        let y = data[i].y;
        let r = data[i].r;
        fill(255);
        noStroke();
        ellipse(x, y, r, r);
    }

}

function setup(){
    createCanvas(width, height);
    background(0);
    range = width/10;
    root = new Node(width/2, height/2, range);
    root.insert(data);
    drawGrid();
    drawPoints();

}

function draw(){
    background(0);
    drawGrid();
    drawPoints();
    range.x = mouseX;
    range.y = mouseY;
    drawRange();
    
}

