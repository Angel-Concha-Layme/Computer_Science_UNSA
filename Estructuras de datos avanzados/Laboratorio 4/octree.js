function pad(n, width, z){
	z = z || '0';
	n = n + '';
	return n.length >= width ? n : new Array(width - n.length +1).join(z) + n;
}

function numberToBinaryString(n){
	let numberInString = Number((n >>> 0).toString(2));
	numberInString = pad(numberInString, 8);
	return numberInString;
}


class ArrayNodes{
    constructor(){
        this.array = [];
    }
    init(){
        for(var i=0;i<8;i++){
            let tempNode = new Node(true,null,null);
            this.array.push(tempNode);
        }
    }
}

class Node{
    constructor(leaf,color){
        this.leaf=leaf; 
        this.color=color;
        this.pixelCount= 0;
        this.colorInRgb;
        this.array= new ArrayNodes;
        this.#isLeaf();
    }
    
    #isLeaf(){
        if(!this.leaf){
            this.array.init();
        }
    }

    setLeaf(leaf){
        this.leaf = leaf;
        this.#isLeaf();
    }
    
    insertColor(colorRgb, colorInOctal, indice){
        if(this.leaf){
            this.pixelCount ++;
            this.colorInRgb = colorRgb;
        }
        if(indice == 8)
            return;
        this.array.array[colorInOctal[indice]].color = colorInOctal[indice];
        this.array.array[colorInOctal[indice]].insertColor(colorRgb, colorInOctal, indice + 1);
        
    }

    setColor(color, colorInOctal, indice){
        if(this.leaf){
            color.red =  this.colorInRgb.red;
            color.green =  this.colorInRgb.green;
            color.blue =  this.colorInRgb.blue;
            return;
        }
        this.array.array[colorInOctal[indice]].color = colorInOctal[indice];
        this.array.array[colorInOctal[indice]].setColor(color, colorInOctal, indice + 1);
    }

    /*!*/
    initHeight(height){
        if(height==1){
            for(let i = 0; i < 8; ++i){
                this.array.array[i].setLeaf(true);
            }            
            return;
        }
        for(var i=0;i<8;i++){
            this.array.array[i].setLeaf(false);
            this.array.array[i].initHeight(height-1);
        }
    }
}

/*Defina la clase node del Octree. El nodo debe almacenar un color en RGB, un contador (para
saber cuantos pixeles tienen ese color) y un flag para saber si es nodo hoja.*/

class Octree{
    constructor(){
        this.head = new Node(false,null,null);
        this.height = 0;
        this.head.initHeight(8);      
    }

    fill(matriz){
        for(let i = 0; i < matriz.length; ++i){
            let red = numberToBinaryString(matriz[i].red);
            let green = numberToBinaryString(matriz[i].green);
            let blue = numberToBinaryString(matriz[i].blue);
            let colorFinalTransformation = [];
            for(let j = 0; j< 8; ++j){
                let octal = red[j] + green[j] + blue[j];
                let octalInDecimal = parseInt(octal, 2);
                colorFinalTransformation.push(octalInDecimal);
            }
            this.head.insertColor(matriz[i], colorFinalTransformation, 0);
        }
    }

    reduction(node){
        if(node.array.array[0].leaf == true ){
            var red = 0, green = 0, blue = 0, pixelCount = 0;
            
            for(let i = 0; i < 8; ++i){
                if(node.array.array[i].pixelCount === 0){
                    continue;
                }
                red += node.array.array[i].colorInRgb.red * node.array.array[i].pixelCount;
                green += node.array.array[i].colorInRgb.green * node.array.array[i].pixelCount;
                blue += node.array.array[i].colorInRgb.blue * node.array.array[i].pixelCount;
                pixelCount += node.array.array[i].pixelCount;
            }

            node.leaf = true;
            node.pixelCount = pixelCount;
            if(pixelCount > 0 ) {
                var color = new Color( parseInt(red / pixelCount), parseInt(green / pixelCount), parseInt(blue / pixelCount));
                node.colorInRgb = color;
            }
            node.array = [];

        } else {
            for(let i = 0; i < 8; ++i) {
                this.reduction(node.array.array[i]);
            }
        }
    }

    reconstruction(matriz){
        for(let i = 0; i < matriz.length; ++i){
            let red = numberToBinaryString(matriz[i].red);
            let green = numberToBinaryString(matriz[i].green);
            let blue = numberToBinaryString(matriz[i].blue);
            let colorFinalTransformation = [];
            for(let j = 0; j< 8; ++j){
                let octal = red[j] + green[j] + blue[j];
                let octalInDecimal = parseInt(octal, 2);
                colorFinalTransformation.push(octalInDecimal);
            }
            this.head.setColor(matriz[i], colorFinalTransformation, 0);

        }
    }
    
    pallete(nodo, mat){
        if(nodo.leaf && nodo.pixelCount > 0){
            mat.push(nodo.colorInRgb);
            return;
        }else if(nodo.leaf && nodo.color === null){
            return;
        }
        for(let i =0; i < 8; ++i){
            this.pallete(nodo.array.array[i], mat);
        }
    }
}
