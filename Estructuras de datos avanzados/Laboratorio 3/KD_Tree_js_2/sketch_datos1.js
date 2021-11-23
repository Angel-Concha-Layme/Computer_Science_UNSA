function setup(){
    var width = 250;
    var height = 200;

    var canvas = createCanvas(width, height);
    canvas.parent('sketch_holder');
    background(0);
    for( var x = 0; x < width; x += width / 10){
        for( var y = 0; y < height; y += height /5){
            stroke(125, 125, 125);
            strokeWeight(1);
            line(x, 0, x, height);
            line(0, y, width, y);
        }
    }

    var point = [140, 90];
    
    let point1 = new N_Point([40, 70]);
    let point2 = new N_Point([70, 130]);
    let point3 = new N_Point([90, 40]);
    let point4 = new N_Point([110, 100]);
    let point5 = new N_Point([140, 110]);
    let point6 = new N_Point([160, 100]);

    let data = [point1, point2, point3, point4, point5, point6];
    
    //build KD-tree with data

    var dataChange = data.slice(); //variable temporal porque la siguiente linea modifica data!!!!!
    var dataKNN = data.slice();

    var root = buildKDTree(dataChange);
    console.log(root);

    // closest point
    var closestPoint = closest_point_brute_force (data, point);
    
    console.log("CLOSEST POINT BRUTE FORCE : "+ closestPoint);

    closestPoint = closest_point(root, point);
    console.log("CLOSEST POINT NAIVE : "+ closestPoint.point.vectorialSpace);

    //KNN(dataKNN, 5, point);
    
    //plot points
    var x =  point[0];
    var y =  point[1];

    fill(81, 209, 246);
    circle(x, height - y, 7);
    textSize(8);
    text(x + ',' + y, x + 5, height - y);


    for(let i=0;i<data.length;i++){
        x = data[i].vectorialSpace[0];
        y = data[i].vectorialSpace[1];
        fill(255, 255, 255);
        circle(x, height - y, 7);
        textSize(8);
        text(x + ',' + y, x + 5, height - y);
    }
    
    x = closestPoint.point.vectorialSpace[0];
    y = closestPoint.point.vectorialSpace[1];
    fill(57, 255, 20);
    circle(x, height - y, 7);
    textSize(8);
    text(x + ',' + y, x + 5, height - y);
    
    // plot graph
    var graph = generateDot(root);

   var options = {
        format: 'svg'
    }
      
    var image = Viz(graph, options);
    var graph_holder = document.getElementById('graph_holder');
    
    graph_holder.innerHTML = image;		// SVG
}
