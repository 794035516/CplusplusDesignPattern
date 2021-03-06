#pragma once
/*
fly action in the animal to dynamically arrange
*/
class FlyAction{
public:
    virtual void fly();
};

class FlyWithWings : public FlyAction{
    void fly();
};

class FlyWithThrow : public FlyAction{
    void fly();
};

class FlyNope : public FlyAction{
    void fly();
};

/*
eat action in the animal to dynamically arrange
*/
class EatAction{
public:
    virtual void eat();
};

class EatWithTeeth : public EatAction{
    void eat();
};

class EatNope : public EatAction{
    void eat();
};

class EatWithSwallow : public EatAction{
    void eat();
};

/*
animal has 2 action can be dynamically arranged
*/
class Animal{
 public:
    Animal();
    Animal(FlyAction* flyAction, EatAction* eatAction);
    int setFlyAction(FlyAction* FlyAction);
    int setEatAction(EatAction* eatAction);
    int performFly();
    int performEat();
    virtual int display();
 protected:
    FlyAction* flyAction;
    EatAction* eatAction;

};

class Dog : public Animal
{
 public:
    Dog();
    int display();
};

class Cat : public Animal
{
 public:
    Cat();
    int display();
};

class Bird : public Animal
{
 public:
    Bird();
    int display();
};
