void main() {
  var hello = "Hello";
  final world = "world";
  print("$hello $world");

  var helloWorld = "Hello " "world";
  print(helloWorld);

  print("helloWorld lenght is ${helloWorld.length}");

  print("helloWorld lenght + 5 is ${helloWorld.length + 5}");

  var div = """
<div>
  <span>Hello world</span>
</div>>
  """;
  print(div);

  var obj = new Object();
  print(obj.toString());
  print(obj);
  print("$obj");
}
