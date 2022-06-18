#pragma once
#include<iostream>
#include<string.h>

enum CupCapability
{
    smallCup,
    mediumCup,
    largeCup
};

/*
 can be decorator decorated
*/
class Beverage
{
 public:
    Beverage();
    Beverage(CupCapability cupSize, double cost, std::string name);
    virtual int showName() const;
    double getCost() const;
    CupCapability getSize() const;
    virtual std::string getName() const;

 protected:
    std::string name;
    double cost;
    CupCapability cupSize;
};

class Milk : public Beverage
{
 public:
    Milk();
    Milk(CupCapability cupSize, double cost, std::string name);
};

class Cola : public Beverage
{
 public:
    Cola();
    Cola(CupCapability cupSize, double cost, std::string name);
};

/*
need to operate the outside 
*/
class Decorator : public Beverage
{
 public:
    Decorator(Beverage* beverage);
    Decorator(Beverage* beverage, double cost, std::string name);

    //0 indicated success, -1 fail
    virtual int searchName(std::string name) const;
    virtual int showName() const;
    virtual std::string getName() const;
    virtual int showDecoration() const;
    virtual double getCost() const;


 protected:
    Beverage* beverage;
};

class Whip : public Decorator
{
 public:
    Whip(Beverage* beverage);
    Whip(Beverage* beverage, double cost, std::string name);
};

class Soy : public Decorator
{
 public:
    Soy(Beverage* beverage);
    Soy(Beverage* beverage, double cost, std::string name);
};

class Pearl : public Decorator
{
 public:
    Pearl(Beverage* beverage);
    Pearl(Beverage* beverage, double cost, std::string name);
};

class Bean: public Decorator
{
 public:
    Bean(Beverage* beverage);
    Bean(Beverage* beverage, double cost, std::string name);
};