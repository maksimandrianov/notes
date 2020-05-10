int sum(int a, int b) => a + b;

void funcWithOptPos(int a, [int b, int c=1]) {
  print("funcWithOpt($a $b $c)");
}

void funcWithOptNamed(int a, {int b:1, int c}) {
  print("funcWithOpt($a $b $c)");
}

int funcWithFunc1(int sum(int a, int b), int a , int b) {
  return sum(a, b);
}

typedef int SumFunc(int a, int b);

int funcWithFunc2(SumFunc sum, int a , int b) {
  return sum(a, b);
}

Function getSumClosure(int val) {
  return (int a) {
    return val + a;
  };
}

void main() {
  print(sum(4, 7));

  var varSum = sum;

  print(varSum(3, 4));

  var mult = (int a, int b) {
    return a * b;
  };

  print(mult(3, 4));

  funcWithOptPos(1);
  funcWithOptPos(1, 2);
  funcWithOptPos(1, 2, 3);

  funcWithOptNamed(1);
  funcWithOptNamed(1, b:2);
  funcWithOptNamed(1, b:2, c:3);

  print(varSum is Object);
  print(varSum is Function);

  print("${funcWithFunc1(sum, 4, 8)}");
  print("${funcWithFunc2(sum, 4, 8)}");

  var sum5 = getSumClosure(5);
  print("${sum5(2)}");
}