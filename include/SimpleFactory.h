#pragma once
#include<map>



class Pizza
{
 public:
    enum PizzaEnum
    {
        Normal,
        Cheese,
        Veggie,
        Clam,
        Pepperoni
    };
    Pizza();
    Pizza(PizzaEnum pizza);

    virtual int taste();
    int display();
    PizzaEnum getType() const;

    std::map<PizzaEnum, std::string> pizzaStr;
 private:
    PizzaEnum type;
};

class CheesePizza : public Pizza
{
 public:
    CheesePizza();
    CheesePizza(PizzaEnum pizza);
    int taste();
};

class VeggiePizza : public Pizza
{
 public:
    VeggiePizza();
    VeggiePizza(PizzaEnum pizza);
    int taste();
};

class ClamPizza : public Pizza
{
 public:
    ClamPizza();
    ClamPizza(PizzaEnum pizza);
    int taste();
};

class PepperoniPizza : public Pizza
{
 public:
    PepperoniPizza();
    PepperoniPizza(PizzaEnum pizza);
    int taste();
};

class SimFactory
{
 public:
 int cook(Pizza::PizzaEnum pizza);
 virtual Pizza* make(Pizza::PizzaEnum pizza);

};