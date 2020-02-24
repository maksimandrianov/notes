#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Pizza
{
 public:
  Pizza(const std::string &name, const std::string &dough,
        const std::string &sauce)
      : _name(name), _dough(dough), _sauce(sauce)
  {
  }
  virtual ~Pizza() {}

  void addTopping(const std::string &topping) { _toppings.push_back(topping); }
  std::string getName() const { return _name; }

  virtual void prepare()
  {
    std::cout << "Preparing " << _name << std::endl;
    std::cout << "Tossing dough.." << std::endl;
    std::cout << "Adding sauce.." << std::endl;
    std::cout << "Adding toppings:" << std::endl;
    for (const auto &topping : _toppings) std::cout << topping << std::endl;
  }

  virtual void bake()
  {
    std::cout << "Bake for 25 minutes at 350" << std::endl;
  }

  virtual void cut()
  {
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
  }

  virtual void box()
  {
    std::cout << "Place pizza in official PizzaStore bix" << std::endl;
  }

 private:
  std::string _name;
  std::string _dough;
  std::string _sauce;
  std::vector<std::string> _toppings;
};

class NYStyleCheesePizza : public Pizza
{
 public:
  NYStyleCheesePizza()
      : Pizza("NY Style Sauce and Cheeese Pizza", "Thin Crust Dough",
              "Marinara Sauce")
  {
    addTopping("Greated Reggiano Cheese");
  }
};

class ChicagoStyleCheesePizza : public Pizza
{
 public:
  ChicagoStyleCheesePizza()
      : Pizza("Chicago Style Deep Dish Cheese Pizza", "Extra Thick Crust Dough",
              "Plum Tomato Sauce")
  {
    addTopping("Shredded Mozzarella Cheese");
  }

  void cut() override
  {
    std::cout << "Cutting the pizza into square slices" << std::endl;
  }
};

enum class PizzaType {
  CHEESE_PIZZA,
};

class PizzaStore
{
 public:
  ~PizzaStore() {}

  std::shared_ptr<Pizza> orderPizza(PizzaType type)
  {
    std::shared_ptr<Pizza> pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
  }

 protected:
  virtual std::shared_ptr<Pizza> createPizza(PizzaType type) = 0;
};

class NYPizzaStore : public PizzaStore
{
 public:
  std::shared_ptr<Pizza> createPizza(PizzaType type)
  {
    switch (type) {
    case PizzaType::CHEESE_PIZZA:
      return std::make_shared<NYStyleCheesePizza>();
    default:
      return std::shared_ptr<Pizza>();
    }
  }
};

class ChicagoPizzaStore : public PizzaStore
{
 public:
  std::shared_ptr<Pizza> createPizza(PizzaType type)
  {
    switch (type) {
    case PizzaType::CHEESE_PIZZA:
      return std::make_shared<ChicagoStyleCheesePizza>();
    default:
      return std::shared_ptr<Pizza>();
    }
  }
};

int main()
{
  std::unique_ptr<PizzaStore> nyStore(new NYPizzaStore());
  std::unique_ptr<PizzaStore> chStore(new ChicagoPizzaStore());

  nyStore->orderPizza(PizzaType::CHEESE_PIZZA);

  std::cout << std::endl;

  chStore->orderPizza(PizzaType::CHEESE_PIZZA);

  return 0;
}
