#include<iostream>
#include<stdlib.h>
#include"include/strategy.h"

Animal::Animal(){
    flyAction = new FlyNope();
    eatAction = new EatNope();
}

Animal::Animal(FlyAction* flyAction, EatAction* eatAction)
{
    this->flyAction = flyAction;
    this->eatAction = eatAction;
}

int Animal::setEatAction(EatAction* eatAction)
{
    this->eatAction = eatAction;
    return 0;
}

int Animal::setFlyAction(FlyAction* flyAction)
{
    this->flyAction = flyAction;
    return 0;
}

int Animal::performFly()
{
    flyAction->fly();
    return 0;
}

int Animal::performEat()
{
    eatAction->eat();
    return 0;
}

int Animal::display()
{
    std::cout<<"I am an animal"<<std::endl;
    return 0;
}

void FlyAction::fly()
{
    std::cout<<"default fly action..."<<std::endl;
}

void FlyWithThrow::fly()
{
    std::cout<<"I can fly by somebody throw me, how pitiful I am"<<std::endl;
}

void FlyWithWings::fly()
{
    std::cout<<"I can fly with wings!!!"<<std::endl;
}

void FlyNope::fly()
{
    std::cout<<"sorry, I cannot fly."<<std::endl;
}

void EatAction::eat()
{
    std::cout<<"default eat action..."<<std::endl;
}

void EatNope::eat()
{
    std::cout<<"I eat nothing"<<std::endl;
}

void EatWithTeeth::eat()
{
    std::cout<<"I eat food with my teeth!!!"<<std::endl;
}

void EatWithSwallow::eat()
{
    std::cout<<"I eat food just through swallow..."<<std::endl;
}

Dog::Dog()
{
    flyAction = new FlyNope();
    eatAction = new EatWithTeeth();
}

int Dog::display()
{
    std::cout<<"I am a dog"<<std::endl;
    return 0;
}


Bird::Bird()
{
    flyAction = new FlyWithWings();
    eatAction = new EatWithSwallow();
}

int Bird::display()
{
    std::cout<<"I am a bird"<<std::endl;
    return 0;
}
