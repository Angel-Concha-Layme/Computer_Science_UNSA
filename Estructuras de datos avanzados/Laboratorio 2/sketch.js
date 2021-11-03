let qtree;

function setup() {
  createCanvas(800, 800);
  background(255);
  let boundary = new Rectangle(400, 400, 400, 400);
  qtree = new QuadTree(boundary, 4);
  for (let i = 0; i < 1000; i++) {
    let x = randomGaussian(width / 2, width / 8);
    let y = randomGaussian(height / 2, height / 8);
    let p = new Point(x, y);
    qtree.insert(p);
  }
}

function draw() {
  background(0);
  qtree.show();

  stroke(255, 0, 0);
  rectMode(CENTER);
  let range = new Rectangle(mouseX, mouseY, 50, 50);

  if (mouseX < width && mouseY < height) {
    rect(range.x, range.y, range.w * 2, range.h * 2);
    let points = qtree.query(range);
    for (let p of points) {
      strokeWeight(4);
      point(p.x, p.y);
    }
  }
}