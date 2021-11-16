//kdtree in 3D
K = 2;
size = 12;
class Node{
    constructor(point, left, right, axis){
        this.point = point;
        this.left = left;
        this.right = right;
        this.axis = axis;
    }
}

function orderx(a, b){
    if(a.point.x < b.point.x) return -1;
    if(a.point.x > b.point.x) return 1;
    return 0;
}
function ordery(a, b){
    if(a.point.y < b.point.y) return -1;
    if(a.point.y > b.point.y) return 1;
    return 0;
}

function orderz(a, b){
    if(a.point.z < b.point.z) return -1;
    if(a.point.z > b.point.z) return 1;
    return 0;
}

function build_kdtree(points , axis){
    if(points.length == 0) return null;
    points.sort(axis == 0 ? orderx : axis == 1 ? ordery : orderz);
    let median = Math.floor(points.length / 2);
    let point = points[median];
    let left = [];
    let right = [];
    for(let i = 0; i < points.length; i++){
        if(i != median){
            if(axis == 0){
                if(points[i].x < point.x) left.push(points[i]);
                else right.push(points[i]);
            }
            else if(axis == 1){
                if(points[i].y < point.y) left.push(points[i]);
                else right.push(points[i]);
            }
            else{
                if(points[i].z < point.z) left.push(points[i]);
                else right.push(points[i]);
            }
        }
    }
    return new Node(point, build_kdtree(left, (axis + 1) % k), build_kdtree(right, (axis + 1) % k), axis);
}


function getHeight(node){
    if(node == null) return 0;
    return Math.max(getHeight(node.left), getHeight(node.right)) + 1;
}

function getGraf(node){
    let r = "";
    if (node.left != null)
    {
        r += `    "` + node.point + `" -> "` + node.left.point + `";\n`;
        r += getGraf(node.left);
    }
    if (node.right != null)
    {
        r += `    "` + node.point + `" -> "` + node.right.point + `";\n`;
        r += getGraf(node.right);
    }
    return r;
}
function generate_dot(node){
    let dot_i = `digraph G\n{\n`;
    let conten = getGraf(node);
    let dot_f = `}`;
    let result = dot_i + conten + dot_f;
    console.log(result);
}

function closest_point_brute_force(points, point){
    let closest = points[0];
    let closest_distance = distance(point, closest);
    for(let i = 1; i < points.length; i++){
        let distance_i = distance(point, points[i]);
        if(distance_i < closest_distance){
            closest = points[i];
            closest_distance = distance_i;
        }
    }
    return closest;
}

function naive_closest_point(node, point, best_distance, best_point){
    if(node == null) return;
    let distance_i = distance(point, node.point);
    if(distance_i < best_distance){
        best_distance = distance_i;
        best_point = node.point;
    }
    let axis = node.axis;
    let compare = (axis == 0 ? point.x : axis == 1 ? point.y : point.z);
    if(compare < node.point[axis]){
        naive_closest_point(node.left, point, best_distance, best_point);
    }
    else{
        naive_closest_point(node.right, point, best_distance, best_point);
    }
    return best_point;
}

function closest_point(node, point, best_distance, best_point){
    if(node == null) return;
    let distance_i = distance(point, node.point);
    if(distance_i < best_distance){
        best_distance = distance_i;
        best_point = node.point;
    }
    let axis = node.axis;
    let compare = (axis == 0 ? point.x : axis == 1 ? point.y : point.z);
    if(compare < node.point[axis]){
        closest_point(node.left, point, best_distance, best_point);
    }
    else{
        closest_point(node.right, point, best_distance, best_point);
    }
    return best_point;
}

function knn(node, point, k, best_points){
    if(node == null) return;
    let distance_i = distance(point, node.point);
    if(best_points.length < k){
        best_points.push(node.point);
        best_points.sort(axis == 0 ? orderx : axis == 1 ? ordery : orderz);
    }
    else{
        if(distance_i < best_points[k - 1][0]){
            best_points.push(node.point);
            best_points.sort(axis == 0 ? orderx : axis == 1 ? ordery : orderz);
            best_points.pop();
        }
    }
    let axis = node.axis;
    let compare = (axis == 0 ? point.x : axis == 1 ? point.y : point.z);
    if(compare < node.point[axis]){
        knn(node.left, point, k, best_points);
    }
    else{
        knn(node.right, point, k, best_points);
    }
    return best_points;
}

function range_query_circle(node, point, radius, queue){
    if(node == null) return;
    let distance_i = distance(point, node.point);
    if(distance_i < radius){
        queue.push(node.point);
    }
    let axis = node.axis;
    let compare = (axis == 0 ? point.x : axis == 1 ? point.y : point.z);
    if(compare < node.point[axis]){
        range_query_circle(node.left, point, radius, queue);
    }
    else{
        range_query_circle(node.right, point, radius, queue);
    }
    return queue;
}

function range_query_rectangle(node, center, width, height, queue){
    if(node == null) return;
    let distance_i = distance(center, node.point);
    if(distance_i < width / 2 && distance_i < height / 2){
        queue.push(node.point);
    }
    let axis = node.axis;
    let compare = (axis == 0 ? center.x : axis == 1 ? center.y : center.z);
    if(compare < node.point[axis]){
        range_query_rectangle(node.left, center, width, height, queue);
    }
    else{
        range_query_rectangle(node.right, center, width, height, queue);
    }
    return queue;
}
