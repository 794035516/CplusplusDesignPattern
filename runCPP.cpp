#ifndef _RUNMODE_H_
#include"include/runCPP.h"
#endif

int RunSpace::runError()
{
    std::cout<<"quit the game"<<std::endl;
    return -1;
}

int RunSpace::runStrategy()
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

int RunSpace::runObserver()
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

int RunSpace::runDecorator()
{
    Beverage* milk = new Milk();
    Soy* milk1 = new Soy(milk);
    printf("this beverage named:%s\n", milk1->getName().c_str());
    printf("this beverage costs :%.1f\n", milk1->getCost());
    milk1->searchName("milk");
    milk1->showDecoration();
    printf(" --- \n");

    Beverage* cola = new Cola(largeCup, 10.1, "cola");
    Whip* cola1 = new Whip(cola, 3.2, "whip");
    Pearl* cola2 = new Pearl(cola1, 2.7, "pearl");
    Bean* cola3 = new Bean(cola2, 4.9, "bean");
    printf("this beverage named:%s\n",cola3->getName().c_str());
    printf("this beverage costs :%.1f\n",cola3->getCost());
    cola3->searchName("Juice");
    cola3->searchName("cola");
    cola3->showDecoration();
    cola3->showName();
    return 0;
}


void RunCPP::setDoFuns(int num, std::function<int()> fun)
{
    doFuns.insert(std::pair<int, std::function<int()>>(num, fun));
    return;
}

void RunCPP::setShowFuns(int num, std::string str)
{
    showFuns.insert(std::pair<int, std::string>(num, str));
    return;
}

std::function<int()> RunCPP::getDoFuns(int num) const
{
    return doFuns.at(num);
}

std::string RunCPP::getShowFuns(int num) const
{
    return showFuns.at(num);
}

std::map<int, std::string> RunCPP::getAllShowFuns() const
{
    return showFuns;
}

RunCPP::RunCPP()
{
    if(!doFuns.empty())
    {
        doFuns.clear();
    }
    setDoFuns(-1, RunSpace::runError);
    setDoFuns(1, RunSpace::runStrategy);
    setDoFuns(2, RunSpace::runObserver);
    setDoFuns(3, RunSpace::runDecorator);
    if(!showFuns.empty())
    {
        showFuns.clear();
    }
    setShowFuns(-1, "error input");
    setShowFuns(1, "Strategy mode");
    setShowFuns(2, "Observer mode");
    setShowFuns(3, "Decorator mode");
}


RunCPP* RunCPP::singletonInstance = nullptr;
RunCPP* RunCPP::getInstance()
{
    if(RunCPP::singletonInstance == nullptr)
    {
        singletonInstance = new RunCPP();
    }
    return RunCPP::singletonInstance;
}