#ifndef _RUNCPP_H_
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

int RunSpace::runCommands()
{
    std::vector<Command*> onCommand(5);
    std::vector<Command*> offCommand(5);
    std::cout<<"initialize noCommand"<<std::endl;
    for(int i = 0; i < onCommand.size();i++)
    {
        onCommand.at(i) = new NoCommand();
    }
    for(int i = 0; i < offCommand.size();i++)
    {
        offCommand.at(i) = new NoCommand();
    }
    onCommand.at(2)->run();
    std::cout<<"set part value"<<std::endl;

    TV* tv = new TV("television");
    Music* music = new Music("Jay");
    Light* light = new Light("intelligence");
    Machine* machine = new Machine("xiao ai");

    MusicParty* musicParty = new MusicParty("happy music", music, light, tv);
    MovieParty* movieParty = new MovieParty("silence movie", machine, tv, light);

    MusicOnCommand* musicOn = new MusicOnCommand(music);
    MusicOffCommand* musicOff = new MusicOffCommand(music);
    LightOnCommand* lightOn = new LightOnCommand(light);
    LightOffCommand* lightOff = new LightOffCommand(light);
    TVOnCommand* tvOn = new TVOnCommand(tv);
    TVOffCommand* tvOff = new TVOffCommand(tv);
    MachineOnCommand* machineOn = new MachineOnCommand(machine);
    MachineOffCommand* machineOff = new MachineOffCommand(machine);

    MusicPartyOnMacCMD* musicPartyOn = new MusicPartyOnMacCMD(musicParty);
    MusicPartyOffMacCMD* musicPartyOff = new MusicPartyOffMacCMD(musicParty);

    MoviePartyOnMacCMD* moviePartyOn = new MoviePartyOnMacCMD(movieParty);
    MoviePartyOffMacCMD* moviePartyyOff = new MoviePartyOffMacCMD(movieParty);

    NoCommand* noCommand = new NoCommand();

    onCommand.at(0) = musicOn;
    onCommand.at(1) = tvOn;
    onCommand.at(3) = lightOn;
    onCommand.at(4) = moviePartyOn;

    offCommand.at(0) = musicOff;
    offCommand.at(1) = tvOff;
    offCommand.at(3) = lightOff;
    offCommand.at(4) = moviePartyyOff;

    std::cout<<"iterator onCommand run"<<std::endl;
    for(Command* i : onCommand)
    {
        i->run();
    }
    std::cout<<"iterator onCommand undo"<<std::endl;
    for(Command* i : onCommand)
    {
        i->undo();
    }
    std::cout<<"iterator offCommand run"<<std::endl;
    for(Command* i : offCommand)
    {
        i->run();
    }
    std::cout<<"iterator offCommand undo"<<std::endl;
    for(Command* i : offCommand)
    {
        i->undo();
    }

    onCommand.at(3) = machineOn;
    offCommand.at(3) = machineOff;

    onCommand.at(4) = musicPartyOn;
    offCommand.at(4) = musicPartyOff;
    for(Command* i : onCommand)
    {
        i->run();
    }
    for(Command* i : offCommand)
    {
        i->run();
    }

    return 0;
}

int RunSpace::runAdapter()
{
    Dog* dog = new Dog();
    Turkey* turkey = new DogAdapter(dog);
    std::cout<<"dog display: "<<dog->display();
    std::cout<<"dog adapts to turkey show method: "<<turkey->show(); 
    std::cout<<"dog adapts to turkey display method: "<<turkey->display();
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
    setDoFuns(STRATEGY , RunSpace::runStrategy);
    setDoFuns(OBSERVER , RunSpace::runObserver);
    setDoFuns(DECORATOR, RunSpace::runDecorator);
    setDoFuns(COMMANDS , RunSpace::runCommands);
    setDoFuns(ADAPTER , RunSpace::runAdapter);
    if(!showFuns.empty())
    {
        showFuns.clear();
    }
    setShowFuns(-1, "error input");
    setShowFuns(STRATEGY , "Strategy mode");
    setShowFuns(OBSERVER , "Observer mode");
    setShowFuns(DECORATOR, "Decorator mode");
    setShowFuns(COMMANDS , "Command mode");
    setShowFuns(ADAPTER  , "Adapter mode");
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