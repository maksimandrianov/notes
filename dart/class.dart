abstract class IAnimal {
  void sayMyName();

  set name(String value);

  // The non-abstract class 'Cat' is missing implementations for these member
  // - IAnimal.saySmt
  // void saySmt();

  factory IAnimal(String name) {
    return new Cat(name);
  }
}

class Cat implements IAnimal {
  var type;
  var _name;

  Cat(String name) {
    _name = name;
  }

  void sayMyName() {
    print("My name is ${this.name}");
    // print("My name is $_name");
  }

  get name => _name;
  set name(String value) => _name = value;
}

void main() {
  var cat = new Cat("Kitty");
  cat.type = "Siamese cat";

  cat.sayMyName();

  print(cat.type);
  print(cat.name);

  cat.name = "Pretty Kitty";

  print(cat.name);

  // It's OK. Private elements such as fields, methods, library functions, and
  // classes are private within a library. Privacy is indicated by an _ prefix.
  // Users of the library can’t access private elements.
  print(cat._name);

  IAnimal animal = new IAnimal("Nikky");
  animal.sayMyName();
}