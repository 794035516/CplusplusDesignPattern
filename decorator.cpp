#ifndef _DECORATOR_H_
#include "include/decorator.h"
#endif

Beverage::Beverage()
{
    name = "unknown Beverage";
    cost = 0;
    cupSize = smallCup;
}

Beverage::Beverage(CupCapability cupSize, double cost, std::string name)
{
    this->cupSize = cupSize;
    this->cost = cost;
    this->name = name;
}

CupCapability Beverage::getSize() const
{
    return cupSize;
}

int Beverage::showName() const
{
    printf("Beverage name:%s\n", name.c_str());
    return 0;
}

double Beverage::getCost() const
{
    return cost;
}

std::string Beverage::getName() const
{
    return name;
}

// test content in the curly brackets would cover the parent class
Milk::Milk():Beverage()
{
    name = "Milk";
   // cost = 0;
    //cupSize = smallCup;
}

Milk::Milk(CupCapability cupSize, double cost, std::string name):Beverage(cupSize,cost,name){}

Cola::Cola():Beverage()
{
    name = "Cola";
 //   cost = 0;
  //  cupSize = smallCup;
}

Cola::Cola(CupCapability cupSize, double cost, std::string name):Beverage(cupSize,cost,name){}


Decorator::Decorator(Beverage* beverage):Beverage()
{
    this->beverage = beverage;
    cost = 0;
    cupSize = beverage->getSize();
    name = "unKnown Decorator";
}

Decorator::Decorator(Beverage* beverage, double cost, std::string name)
{
    this->beverage = beverage;
    this->cost = cost;
    this->cupSize = beverage->getSize();
    this->name = name;
}

std::string Decorator::getName() const
{
    return beverage->getName() + "," + name;
}

int Decorator::showName() const
{
    printf("this beverage includes:%s\n", getName().c_str());
    return 0;
}

int Decorator::showDecoration() const
{
    std::string show = getName();
    int len = show.find(",");
    show = show.substr(len);
    printf("this beverage includes decoration:%s\n", show.c_str());
    return 0;
}

int Decorator::searchName(std::string name) const
{
    int flag = 1;
    if(this->name == name)
    {
        flag = 0;
    }
    while(beverage && flag)
    {
        if(beverage->getName().find(name) != std::string::npos )
        {
            flag = 0;
        }
        else
        {
            break;
        }
    }
    printf("this beverage %s the %s\n", !flag?"has":"donot have", name.c_str());
    return flag;
}

double Decorator::getCost() const
{
    return beverage->getCost() + cost;
}

Whip::Whip(Beverage* beverage):Decorator(beverage){}
Whip::Whip(Beverage* beverage, double cost, std::string name):Decorator(beverage, cost, name){}
/*
double Whip::getCost() const 
{
    return beverage->getCost() + cost;;
}

std::string Whip::getName() const
{
    return beverage->getName() + name;
}
*/

Soy::Soy(Beverage* beverage):Decorator(beverage){}
Soy::Soy(Beverage* beverage, double cost, std::string name):Decorator(beverage, cost, name){}

Pearl::Pearl(Beverage* beverage):Decorator(beverage){}
Pearl::Pearl(Beverage* beverage, double cost, std::string name):Decorator(beverage, cost, name){}

Bean::Bean(Beverage* beverage):Decorator(beverage){}
Bean::Bean(Beverage* beverage, double cost, std::string name):Decorator(beverage, cost, name){}
