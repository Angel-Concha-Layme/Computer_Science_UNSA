# datos de entrada
scores = [0.9, 0.75, 0.8]
iou_threshold = 0.55
iou_table = [
    [1.000, 0.527, 0.588],
    [0.527, 1.000, 0.341],
    [0.588, 0.341, 1.000]
]



def non_maximum_suppression(scores, iou_table, iou_threshold):
    boxes = sorted(list(enumerate(scores)), key=lambda x: x[1], reverse=True)
    selected_boxes = []
    steps = []

    while boxes:
        current_box = boxes.pop(0)
        selected_boxes.append(current_box)
        steps.append(f"Seleccionamos el bounding box {current_box[0]} con un score de {current_box[1]}.")

        removed_boxes = [box for box in boxes if iou_table[current_box[0]][box[0]] > iou_threshold]
        boxes = [box for box in boxes if iou_table[current_box[0]][box[0]] <= iou_threshold]

        if removed_boxes:
            steps.append(f"Eliminamos los bounding boxes {', '.join(str(box[0]) for box in removed_boxes)} debido a un IOU mayor al umbral con el bounding box {current_box[0]}.\n")
        else:
            steps.append(f"No eliminamos ningún bounding box en esta iteración.\n")
            
    return selected_boxes, steps


nms_boxes, nms_steps = non_maximum_suppression(scores, iou_table, iou_threshold)
print("Los bounding boxes seleccionados son:", nms_boxes)
print("\nPasos del algoritmo:")
for step in nms_steps:
    print(step)
    

"""
OUTPUT:

Los bounding boxes seleccionados son: [(0, 0.9), (1, 0.75)]

Pasos del algoritmo:
Seleccionamos el bounding box 0 con un score de 0.9.
Eliminamos los bounding boxes 2 debido a un IOU mayor al umbral con el bounding box 0.

Seleccionamos el bounding box 1 con un score de 0.75.
No eliminamos ningún bounding box en esta iteración.

"""