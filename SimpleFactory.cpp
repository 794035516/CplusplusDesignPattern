#ifndef _IOSTREAM_
#include<iostream>
#endif
#ifndef _SIMPLEFACTORY_H_
#include"include/SimpleFactory.h"
#endif

Pizza::Pizza()
{
    type = Normal;
    if(!pizzaStr.empty())
    {
        pizzaStr.clear();
    }
}

Pizza::Pizza(PizzaEnum pizza)
{
    type = pizza;
    if(!pizzaStr.empty())
    {
        pizzaStr.clear();
    }
}

int Pizza::taste()
{
    std::cout<<"this tastes normal"<<std::endl;
    return 0;
}

int Pizza::display()
{
    printf("this is a %s pizza\n", pizzaStr.at(type).c_str());
    return 0;
}

Pizza::PizzaEnum Pizza::getType() const
{
    return type;
}

CheesePizza::CheesePizza():Pizza(){}
CheesePizza::CheesePizza(PizzaEnum pizza):Pizza(pizza){}
int CheesePizza::taste()
{
    std::cout<<"when your mouth if full of oil, you will feel that it is not greasy at all"<<std::endl;
    return 0;
}

VeggiePizza::VeggiePizza():Pizza(){}
VeggiePizza::VeggiePizza(PizzaEnum pizza):Pizza(pizza){}
int VeggiePizza::taste()
{
    std::cout<<"Nutritious, Vitamin rich, Crisp"<<std::endl;
    return 0;
}

ClamPizza::ClamPizza():Pizza(){}
ClamPizza::ClamPizza(PizzaEnum pizza):Pizza(pizza){}
int ClamPizza::taste()
{
    std::cout<<"Fleshy and soft"<<std::endl;
    return 0;
}

PepperoniPizza::PepperoniPizza():Pizza(){}
PepperoniPizza::PepperoniPizza(PizzaEnum pizza):Pizza(pizza){}
int PepperoniPizza::taste()
{
    std::cout<<"Very little meat and fat"<<std::endl;
    return 0;
}

Pizza* SimFactory::make(Pizza::PizzaEnum pizzaType)
{
    Pizza* piz;
    if(pizzaType == Pizza::Normal)
    {
        piz = new Pizza();
    }
    else if(pizzaType == Pizza::Veggie)
    {
        piz = new VeggiePizza(pizzaType);
    }
    else if(pizzaType == Pizza::Cheese)
    {
        piz = new CheesePizza(pizzaType);
    }
    else if(pizzaType == Pizza::Clam)
    {
        piz = new ClamPizza(pizzaType);
    }
    return piz;
}

int SimFactory::cook(Pizza::PizzaEnum pizzaType)
{
    Pizza* pizza = SimFactory::make(pizzaType);
    pizza->
}