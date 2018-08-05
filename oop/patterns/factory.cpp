#include <iostream>
#include <memory>
#include <string>

class Dough {
public:
        virtual ~Dough() {}
};

class ThinCrustDough: public Dough {
public:
        ThinCrustDough() {
                std::cout << "ThinCrustDough" << std::endl;
        }
};

class ExtraThickCrustDough: public Dough {
public:
        ExtraThickCrustDough() {
                std::cout << "ExtraThickCrustDough" << std::endl;
        }
};

class Sauce {
public:
        virtual ~Sauce() {}
};

class MarinaraSauce: public Sauce {
public:
        MarinaraSauce() {
                std::cout << "MarinaraSauce" << std::endl;
        }
};

class PlumTomatoSauce: public Sauce {
public:
        PlumTomatoSauce() {
                std::cout << "PlumTomatoSauce" << std::endl;
        }
};

class PizzaIngredientFactoryIntrface {
public:
        virtual ~PizzaIngredientFactoryIntrface() {}
        virtual std::shared_ptr<Dough> createDough() = 0;
        virtual std::shared_ptr<Sauce> createSauce() = 0;
};

class NYPizzaIngredientFactory: public PizzaIngredientFactoryIntrface {
public:
        std::shared_ptr<Dough> createDough() override {
                return std::make_shared<ThinCrustDough>();
        }

        std::shared_ptr<Sauce> createSauce() override {
                return std::make_shared<MarinaraSauce>();
        }
};

class ChicagoPizzaIngredientFactory: public PizzaIngredientFactoryIntrface {
public:
        std::shared_ptr<Dough> createDough() override {
                return std::make_shared<ExtraThickCrustDough>();
        }

        std::shared_ptr<Sauce> createSauce() override {
                return std::make_shared<PlumTomatoSauce>();
        }
};

void createIngredients(std::unique_ptr<PizzaIngredientFactoryIntrface> f) {
        f->createDough();
        f->createSauce();
}

int main() {
        std::unique_ptr<PizzaIngredientFactoryIntrface> nyFactory(new NYPizzaIngredientFactory());
        std::unique_ptr<PizzaIngredientFactoryIntrface> chFactory(new ChicagoPizzaIngredientFactory());

        createIngredients(std::move(nyFactory));
        createIngredients(std::move(chFactory));

        return 0;
}
