# Python implementation of the KD Tree
# Para su uso es necesario instalar la librería matplotlib

from heapq import heappush, heappop
from collections import namedtuple
import matplotlib.pyplot as plt
from treelib import Node, Tree
from math import inf

class Point:
    def __init__(self, data):
        self.data = data
    
    def __str__(self) -> str:
        cadena = "id: "
        cadena += str(self.data[0])
        cadena += " data: {"
        for i in range(1, len(self.data)-1):
            cadena += str(self.data[i]) + ", "
        cadena += str(self.data[len(self.data)-1])
        cadena += "}"
        return cadena       
    
    def distance(self, other):
        return sum([(self.data[i] - other.data[i]) ** 2 for i in range(len(self.data))]) ** 0.5


class Node:
    def __init__(self, point: Point):
        self.point = point
        self.left_child = None
        self.right_child = None

    def set_left_child(self, node):
        self.left_child = node
    def set_right_child(self, node):
        self.right_child = node


Interval = namedtuple('Interval', 'start end')

class Range:
    def __init__(self, n):
        self.n = n
        self.data = [Interval(float('-inf'), float('inf')) for i in range(n)]
    
    def set_range(self):
        print("Ingrese los valores del rango: ")
        for i in range(self.n):
            temp = [eval(item) for item in input().split()]
            intervalo = Interval(float(temp[0]), float(temp[1]))
            self.data[i] = intervalo
    def set_range_with_list(self, items: list):
        for i in range(self.n):
            self.data[i] = Interval(items[i][0], items[i][1])



class KDTree:   
    def __init__(self, dim: int):
        self.root = None
        self.dimension = dim
        self.labels = []
    
    def set_labels(self, labels):
        self.labels = labels

    # axis = i, para i = 0, 1, ..., 11 son las caracteristicas
    def sort_by_axis(self, points: list, axis: int):
        return sorted(points, key=lambda p: p.data[axis])

    def build(self, points: list):
        self.root = self.build_tree(points, 0)
    
    def build_tree(self, points, depth):
        if len(points) == 0:
            return None
        # si solo queda un elemento, ese es el nodo hoja
        if len(points) == 1:
            return Node(points[0])

        # ordenamiento por eje
        points = self.sort_by_axis(points, depth % self.dimension)
        median_idx = len(points) // 2
        median_point = points[median_idx]

        # nodo que se va a retornar
        node = Node(median_point)
        left_child = self.build_tree(points[:median_idx], depth + 1)
        right_child = self.build_tree(points[median_idx + 1:], depth + 1)
        node.set_left_child(left_child)
        node.set_right_child(right_child)
        return node
    
    def is_contained(self, punto: Point, rango: Range):
        if punto is None:
            return False
        for i in range(self.dimension):
            if punto.data[i] < rango.data[i].start or punto.data[i] > rango.data[i].end:
                return False
        return True
    
    def range_query(self, rango: Range):
        print("\nRange query:")
        for i in range(len(rango.data)):
            print(self.labels[i], " --> ", end=" ")
            print("[", rango.data[i].start, ",", rango.data[i].end, "]")
        return self.range_query_rec(self.root, rango, 0)
    
    def range_query_rec(self, node: Node, rango: Range, axis: int):
        if node is None:
            return []
        results = []
        if self.is_contained(node.point, rango):
            results.append(node.point)
        if node.left_child is not None:
            results += self.range_query_rec(node.left_child, rango, (axis + 1) % self.dimension)
        if node.right_child is not None:
            results += self.range_query_rec(node.right_child, rango, (axis + 1) % self.dimension)

        return results


    
    def print_tree(self):
        tree = Tree()
        tree.create_node(str(self.root.point), str(self.root.point))
        tree = self.print_tree_rec(self.root.left_child, str(self.root.point), tree)
        tree = self.print_tree_rec(self.root.right_child, str(self.root.point), tree)
        tree.show()
    
    def print_tree_rec(self, node, name, tree):
        if node is None:
            return tree
        tree.create_node(str(node.point), str(node.point), parent=name)
        tree = self.print_tree_rec(node.left_child, str(node.point), tree)
        tree = self.print_tree_rec(node.right_child, str(node.point), tree)
        return tree

    
    def KNN(self, point: Point, k: int):
        heap = []  # [ (int distance, Point point), ... ]
        self.KNN_rec(self.root, point, heap, k)
        result = []
        for i in range(k+1):
            result.append(heappop(heap)[1])
        return result[1:]
    
    def KNN_rec(self, node: Node, point: Point, heap: list, k: int):
        if node is None:
            return
        heappush(heap, [node.point.distance(point), node.point])
        if node.left_child is not None:
            self.KNN_rec(node.left_child, point, heap, k)
        if node.right_child is not None:
            self.KNN_rec(node.right_child, point, heap, k)
