#include <iostream>
#include <memory>

using namespace std;


class IFlyBehavoir {
public:
        virtual ~IFlyBehavoir() {}
        virtual void Fly() = 0;
};


class IQuackBehavoir {
public:
        virtual ~IQuackBehavoir() {}
        virtual void Quack() = 0;
};


class Dack {
public:
        Dack(IFlyBehavoir *fb, IQuackBehavoir *qb):
                _flyBehavoir(fb),
                _quackBehavoir(qb) {}
        virtual ~Dack() {}
        virtual void Display() = 0;
        void PerformFly() { _flyBehavoir->Fly(); }
        void PerformQuack() { _quackBehavoir->Quack(); }
        void Swim() { cout << "Swim" << endl; }
        void SetFlyBehavoir(IFlyBehavoir *fb) { _flyBehavoir.reset(fb); }
        void SetQuackBehavoir(IQuackBehavoir *qb) { _quackBehavoir.reset(qb); }
private:
        unique_ptr<IFlyBehavoir> _flyBehavoir;
        unique_ptr<IQuackBehavoir> _quackBehavoir;
};


class FlyWithWings: public IFlyBehavoir {
public:
        void Fly() override { cout << "FlyWithWings" << endl; }
};


class FlyNoWay: public IFlyBehavoir {
public:
        void Fly() override { cout << "FlyNoWay" << endl; }
};


class SimpleQuack: public IQuackBehavoir {
public:
        void Quack() override { cout << "SimpleQuack" << endl; }
};


class MuteQuack: public IQuackBehavoir {
public:
        void Quack() override { cout << "MuteQuack" << endl; }
};


class ModelDack: public Dack {
public:
        ModelDack():
                Dack(new FlyNoWay(), new SimpleQuack()) {}

        void Display() override { cout << "Display" << endl; }
};


int main()
{
        unique_ptr<Dack> model(new ModelDack());
        model->PerformFly();
        model->PerformQuack();
        model->Display();

        model->SetFlyBehavoir(new FlyWithWings());
        model->SetQuackBehavoir(new MuteQuack());
        model->PerformFly();
        model->PerformQuack();

        return 0;
}
