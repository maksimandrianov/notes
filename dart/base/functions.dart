int sum(int a, int b) => a + b;

void main() {
  print(sum(4, 7));

  var varSum = sum;

  print(varSum(3, 4));

  var mult = (int a, int b) {
    return a * b;
  };

  print(mult(3, 4));
}