class Point {
    constructor(x, y) {
      this.x = x;
      this.y = y;
    }
  }
  
  class Rectangle {
    constructor(x, y, weight, height) {
      this.x = x;
      this.y = y;
      this.weight = weight;
      this.height = height;
    }
  
    contains(point) {
      return (
        point.x >= this.x - this.weight &&
        point.x < this.x + this.weight &&
        point.y >= this.y - this.height &&
        point.y < this.y + this.height
      );
    }
  
    intersects(range) {
      return !(
        range.x - range.weight > this.x + this.weight ||
        range.x + range.weight < this.x - this.weight ||
        range.y - range.height > this.y + this.height ||
        range.y + range.height < this.y - this.height
      );
    }
  }
  
  class QuadTree {
    constructor(boundary, n) {
      this.boundary = boundary;
      this.capacity = n;
      this.points = [];
      this.divided = false;
    }
  
    subdivide() {
      let x = this.boundary.x;
      let y = this.boundary.y;
      let weight = this.boundary.weight;
      let height = this.boundary.height;
      let ne = new Rectangle(x + weight / 2, y - height / 2, weight / 2, height / 2);
      this.northeast = new QuadTree(ne, this.capacity);
      let nw = new Rectangle(x - weight / 2, y - height / 2, weight / 2, height / 2);
      this.northwest = new QuadTree(nw, this.capacity);
      let se = new Rectangle(x + weight / 2, y + height / 2, weight / 2, height / 2);
      this.southeast = new QuadTree(se, this.capacity);
      let sw = new Rectangle(x - weight / 2, y + height / 2, weight / 2, height / 2);
      this.southwest = new QuadTree(sw, this.capacity);
      this.divided = true;
    }
  
    insert(point) {
      if (!this.boundary.contains(point)) {
        return false;
      }
  
      if (this.points.length < this.capacity) {
        this.points.push(point);
        return true;
      } else {
        if (!this.divided) {
          this.subdivide();
        }
        if (this.northeast.insert(point)) {
          return true;
        } else if (this.northwest.insert(point)) {
          return true;
        } else if (this.southeast.insert(point)) {
          return true;
        } else if (this.southwest.insert(point)) {
          return true;
        }
      }
    }
  
    query(range, found) {
      if (!found) {
        found = [];
      }
      if (!this.boundary.intersects(range)) {
        return;
      } else {
        for (let p of this.points) {
          if (range.contains(p)) {
            found.push(p);
          }
        }
        if (this.divided) {
          this.northwest.query(range, found);
          this.northeast.query(range, found);
          this.southwest.query(range, found);
          this.southeast.query(range, found);
        }
      }
      return found;
    }
  
    show() {
      stroke(255);
      noFill();
      strokeWeight(1);
      rectMode(CENTER);
      rect(
        this.boundary.x,
        this.boundary.y,
        this.boundary.weight * 2,
        this.boundary.height * 2
      );
      for (let p of this.points) {
        strokeWeight(2);
        point(p.x, p.y);
      }
  
      if (this.divided) {
        this.northeast.show();
        this.northwest.show();
        this.southeast.show();
        this.southwest.show();
      }
    }
  }