import "dart:html";
import "dart:math";

void main() {
  CanvasElement canvas = new CanvasElement();
  canvas.width = 300;
  canvas.height = 300;

  document.body.children.add(canvas);

  CanvasRenderingContext2D ctx = canvas.getContext("2d");
  ctx.fillText("Canvas", 80, 10);

  ctx.beginPath();
  ctx.arc(100, 100, 20, 0, 2 * pi);
  ctx.closePath();
  ctx.fill();
}