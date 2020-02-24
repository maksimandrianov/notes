#include <iostream>
#include <memory>
#include <string>

using namespace std;

class IBeverage
{
 public:
  virtual ~IBeverage() {}
  virtual string Description() const = 0;
};

class Beverage : public IBeverage
{
 public:
  string Description() const override { return _description; }
  virtual double Cost() const = 0;

 protected:
  string _description;
};

class CondimentDecorator : public Beverage
{
 public:
  virtual string HardCalc() const = 0;
};

class Espresso : public Beverage
{
 public:
  Espresso() { _description = "Espresso"; }
  double Cost() const override { return 1.99; }
};

class HouseBlend : public Beverage
{
 public:
  HouseBlend() { _description = "HouseBlend"; }
  double Cost() const override { return .89; }
};

class Mocha : public CondimentDecorator
{
 public:
  Mocha(shared_ptr<Beverage> b) : _beverage(b) {}

  string HardCalc() const override { return "Motcha HardCalc"; }

  string Description() const override
  {
    return _beverage->Description() + ", Motcha";
  }

  double Cost() const override { return _beverage->Cost() + .20; }

 private:
  shared_ptr<Beverage> _beverage;
};

class Soy : public CondimentDecorator
{
 public:
  Soy(shared_ptr<Beverage> b) : _beverage(b) {}

  string HardCalc() const override { return "Soy HardCalc"; }

  string Description() const override
  {
    return _beverage->Description() + ", Soy";
  }

  double Cost() const override { return _beverage->Cost() + .5; }

 private:
  shared_ptr<Beverage> _beverage;
};

class Whip : public CondimentDecorator
{
 public:
  Whip(shared_ptr<Beverage> b) : _beverage(b) {}

  string HardCalc() const override { return "Whip HardCalc"; }

  string Description() const override
  {
    return _beverage->Description() + ", Whip";
  }

  double Cost() const override { return _beverage->Cost() + .18; }

 private:
  shared_ptr<Beverage> _beverage;
};

int main()
{
  shared_ptr<Beverage> beverage(new Espresso());
  cout << beverage->Description() << endl;

  beverage = shared_ptr<CondimentDecorator>(new Mocha(beverage));
  cout << beverage->Description() << endl;

  beverage = shared_ptr<CondimentDecorator>(new Whip(beverage));
  cout << beverage->Description() << endl;

  return 0;
}
