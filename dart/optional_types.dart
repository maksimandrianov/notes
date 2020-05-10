anyNull(a, b)  {
  return a == null || b == null;
}

bool anyIntNull(int a, int b)  {
  return a == null || b == null;
}

void main() {
  print(anyNull(1, 2));
  print(anyNull(1, null));

  print(anyIntNull(1, 2));
  print(anyIntNull(1, null));

  // Error: The argument type 'String' can't be assigned to the parameter type 'int'.
  // print(anyIntNull(1, "hello"));
}