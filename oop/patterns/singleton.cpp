#include <iostream>

class Singleton
{
 public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static Singleton &Inctance()
  {
    static Singleton inst;
    return inst;
  }

  void print() { std::cout << "print" << std::endl; }

 private:
  Singleton() {}
  ~Singleton() {}
};

int main() { Singleton::Inctance().print(); }
