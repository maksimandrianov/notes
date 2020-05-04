import "dart:html";

class Item {
  String text;
  DivElement _uiElement;
  bool _isPacket = false;

  Item(String this.text) {

  }

  DivElement get uiElement {
    if (_uiElement == null) {
      _uiElement = new Element.tag("div");
      _uiElement.classes.add("item");
      _uiElement.text = text;
      _uiElement.onClick.listen((event) => isPacket = !isPacket);
    }

    return _uiElement;
  }

  bool get isPacket => _isPacket;

  set isPacket(bool value) {
    _isPacket = value;
    if (_isPacket) {
      _uiElement.classes.add("packed");
    } else {
      _uiElement.classes.remove("packed");
    }
  }
}

void addItem() {
  InputElement input = querySelector("#pl-input");
  DivElement items = querySelector("#pl-items");

  var item = new Item(input.value);
  items.children.add(item.uiElement);

  input.value = "";
}

void main() {
  var title = new Element.html("<h2>Pack list</h2>");
  document.body.children.add(title);

  InputElement input = new Element.tag("input");
  input.id = "pl-input";
  input.placeholder = "Enter an item";
  input.onKeyPress.listen((event) {
      if (event.keyCode == 13) {
        addItem();
      }
  });
  document.body.children.add(input);

  ButtonElement button = new Element.tag("button");
  button.id = "pl-button";
  button.text = "Add";
  button.onClick.listen((event) => addItem());
  document.body.children.add(button);

  DivElement items = new Element.tag("div");
  items.id = "pl-items";
  items.style.width = "300px";
  items.style.border = "1px solid black";
  items.innerHtml = "&nbsp;";
  document.body.children.add(items);
}