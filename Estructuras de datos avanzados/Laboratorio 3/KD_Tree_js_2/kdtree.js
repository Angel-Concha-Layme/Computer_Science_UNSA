k = 2;

class Node {
    constructor(point, axis) {
        this.point = point;
        this.left = null;
        this.right = null;
        this.axis = axis;
    }
};

class N_Point {
    constructor(points) {
        this.vectorialSpace = points;
    }
}

function distanceSquared ( point1 , point2 ){
    var distance = 0;
    for (var i = 0; i < k; i ++)
    distance += Math.pow(( point1 [i] - point2 [i]) , 2) ;
    return Math.sqrt( distance );
}

function closest_point_brute_force ( points , point ) {
    
    var closestPoint;
    var minDistance; 
    var distance;
    for(var i= 0; i< points.length ;i++){
        if(i==0){
            minDistance = distanceSquared(points[0].vectorialSpace,point);
            closestPoint = points[0].vectorialSpace;
        }
        distance = distanceSquared(points[i].vectorialSpace,point);
        
        if(minDistance >= distance ){
            minDistance = distance;
            closestPoint = points[i].vectorialSpace;
        }
    }
    return  closestPoint;
}

function naive_closest_point(node , point , depth = 0, best = null ) {
    if(node != null){
        if(depth == 0){
            best = node.point.vectorialSpace;
        }
       
        var axisDistance = point[node.axis] - node.point.vectorialSpace[node.axis]; 
        let distanceBest = distanceSquared(best, point);
        let distanceNode = distanceSquared(node.point.vectorialSpace,point);


        if ( Math.abs(axisDistance) <= distanceBest ){
            if(distanceBest > distanceNode){
                best = node.point.vectorialSpace;
            }
            if(axisDistance > 0){
                return naive_closest_point (node.right , point , depth+1, best );
            }
            else{
                return naive_closest_point (node.left , point , depth+1, best);
            }
        }else{
            return best;
        }
    }else{
        return best;
    }
}

//////////////////////Practica-07   //////////////////////////////////////////


function range_query_circle(data , center , radio , queue , depth = 0) {
    let neight = [];
    let root = buildKDTree(data);

    for(let i = 0; i < data.length; ++i) {
        let arr = [];
        convertKDTreeToArray(root, arr);
        let closePoint = closest_point(root, center,depth);
        if(distanceSquared( center,closePoint.point.vectorialSpace) < radio){
            neight.push(closePoint.point.vectorialSpace);
        }
        deleteNode(arr, closePoint);
        root = buildKDTree(arr);
    }
    return neight;
}

function range_query_rec(data , center , diameter , queue , depth = 0) {
    let neight = [];
    let root = buildKDTree(data);

    for(let i = 0; i < data.length; ++i) {
        let arr = [];
        convertKDTreeToArray(root, arr);
        let closePoint = closest_point(root, center,depth);
        
        let dimX = [closePoint.point.vectorialSpace[0],0];
        let centerX =[center[0],0];

        let dimY = [0,closePoint.point.vectorialSpace[1]];
        let centerY =[0,center[1]];

        if(distanceSquared(centerX,dimX) < diameter && distanceSquared(centerY,dimY) < diameter){
            neight.push(closePoint.point.vectorialSpace);
        }
        deleteNode(arr, closePoint);
        root = buildKDTree(arr);
    }
    return neight;
}
//////////////////////////////////////////////////////////


function closest_point(node, point, depth = 0) {
    if(node == null) {
        return null;
    }

    if(point[node.axis] < node.point.vectorialSpace[node.axis]) {
        var nextBranch = node.left;
        var otherBranch = node.right;    
    } else {
        var nextBranch = node.right;
        var otherBranch = node.left;
    }

    var temp = closest_point(nextBranch, point, depth + 1);
    var best = closest(temp, node, point);
    
    var distanceBest = distanceSquared(point, best.point.vectorialSpace);
    var distanceAxis = Math.abs(point[node.axis] - node.point.vectorialSpace[node.axis]);

    if(distanceAxis <= distanceBest) {
        temp = closest_point(otherBranch, point, depth + 1);
        best = closest(temp, best, point);
    }
    
    return best;
}

function closest(node, root, point) {
    if(node == null)
        return root;
    if(root == null)
        return node;
    
    let distanceNode = distanceSquared(node.point.vectorialSpace, point);
    let distanceRoot = distanceSquared(root.point.vectorialSpace, point);

    if(distanceNode < distanceRoot)
        return node;
    else
        return root;
}

function convertKDTreeToArray(node,array){
    array.push(node.point);
    if(node.left != null)
        convertKDTreeToArray(node.left,array);
    if(node.right != null)
        convertKDTreeToArray(node.right,array);
}

function KNN(data, n, point) {
    let neight = [];
    let root = buildKDTree(data);

    for(let i = 0; i < n; ++i) {
        let arr = [];
        convertKDTreeToArray(root, arr);
        let closePoint = closest_point(root, point);
        neight.push(closePoint.point.vectorialSpace);
        deleteNode(arr, closePoint);
        root = buildKDTree(arr);
    }
    return neight;
}

function deleteNode(arr, node) {
    for(let i = 0; i < arr.length; ++i) {
        if(arr[i].vectorialSpace == node.point.vectorialSpace)
            arr.splice(i, 1);
    }
}

function getHeight(node) {
    if(node === null)
        return 0;
    
    return Math.max(getHeight(node.left), getHeight(node.right)) + 1;
}

function generateDot(node) {
    var s = "digraph G{\n";
    var cola = [];
    cola.push(node);
    while(cola.length > 0){
        let nodo = (cola.splice(0, 1))[0];
        if(nodo.left == null){
            continue;
        }
        let space = nodo.point.vectorialSpace.length;
        for(let i = 0; i < space - 1; ++i){
            s += "\"";
            s += nodo.point.vectorialSpace[i];
            s += ",";
        }
        s += nodo.point.vectorialSpace[space - 1];
        s += "\" -> ";
        for(let i = 0; i < space - 1; ++i){
            s += "\"";
            s += nodo.left.point.vectorialSpace[i];
            s += ",";
        }
        s += nodo.left.point.vectorialSpace[space -1];
        s += "\";\n";
        cola.push(nodo.left);

        //RIGHT NODE
        if(nodo.right == null){
            continue;
        }
        for(let i = 0; i < space - 1; ++i){
            s += "\"";
            s += nodo.point.vectorialSpace[i];
            s += ",";
        }
        s += nodo.point.vectorialSpace[space - 1];
        s += "\" -> ";
        for(let i = 0; i < space - 1; ++i){
            s += "\"";
            s += nodo.right.point.vectorialSpace[i];
            s += ",";
        }
        s += nodo.right.point.vectorialSpace[space -1];
        s += "\";\n";
        cola.push(nodo.right);
    }
    s += "}"
    return s;
}

function buildKDTree(points, depth = 0) {
    if(points.length === 0) {
        return;
    } else {
        mergeSort(points, 0, points.length - 1, depth % points[0].vectorialSpace.length);
        let median = Math.floor(points.length / 2);
        let root = new Node(points[median], depth % points[0].vectorialSpace.length);
        points.splice(median, 1);
        let leftBranch = points.slice(0, median);
        let rightBranch = points.slice(median, points.length);

        root.left = buildKDTree(leftBranch, depth + 1);
        root.right = buildKDTree(rightBranch, depth + 1);

        return root;
    }
    
}

function mergeSort(points, left, right, dim) {
    let mid = Math.floor((left + right) / 2);

    if(left < right) {
        mergeSort(points, left, mid, dim);
        mergeSort(points, mid + 1, right, dim);
        merge(points, left, mid, right, dim);
    }   
}

function merge(points, left, mid, right, dim) {
    let temp = [];
    let i = left;
    let j = mid + 1;

    while(i <= mid && j <= right) {
        if(points[i].vectorialSpace[dim] <= points[j].vectorialSpace[dim])
            temp.push(points[i++]);
        else
            temp.push(points[j++]);
    }

    while(i <= mid)
        temp.push(points[i++]);
    while(j <= right)
        temp.push(points[j++]);

    for(let i = left, j = 0; i <= right; ++i, ++j)
        points[i] = temp[j];
}
