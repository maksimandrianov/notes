import "dart:html";

void main() {
  var btn = new Element.tag("button");
  btn.text = "I'm button!";
  btn.onClick.listen((event) {
    List buttonList = querySelectorAll("button");
    window.alert("There is ${buttonList.length} button");
  });

  document.body.children.add(btn);
}