#ifndef _RUNMODE_H_
#include"runCPP.h"
#endif
//namespace RunCPP
//{
int RunCPP::runStrategy()
{
    FlyAction* fnope = new FlyNope();
    FlyAction* fthrow = new FlyWithThrow();
    FlyAction* fwings = new FlyWithWings();
    EatAction* enope = new EatNope();
    EatAction* eswallow = new EatWithSwallow();
    EatAction* eteeth = new EatWithTeeth();
    Animal* dog = new Dog();
    Animal* bird = new Bird();
    dog->display();
    dog->performEat();
    dog->performFly();
    dog->setFlyAction(fthrow);
    dog->performFly();
    dog->setEatAction(enope);
    dog->performEat();
    dog->setFlyAction(fwings);
    dog->performFly();
    dog->setEatAction(eteeth);
    dog->performEat();
    std::cout<<"   ---   "<<std::endl;
    bird->display();
    bird->performEat();
    bird->performFly();
    return 0;
}

int RunCPP::runObserver()
{
    News* news = new News();
    Observer* p1 = new People("p1");
    Observer* p2 = new People("p2");
    Observer* p3 = new People("p3");
    Observer* p4 = new People("p4");
    news->registerObserver(p1);
    news->registerObserver(p2);
    news->registerObserver(p3);
    news->registerObserver(p4);
    news->showObservers();
    news->notifyObservers();
    news->removeObserver(p3);
    news->showObservers();
    news->notifyObservers();
    return 0;
}   

//}
