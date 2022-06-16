#ifndef _OBSERVER_H_
#include"include/observer.h"
#endif
#ifndef _ALGORITHM_H_
#include<algorithm>
#endif
#ifndef _STRING_H_
#include<string.h>
#endif

Subject::Subject()
{
    observers.clear();
}

int Subject::registerObserver(Observer* observer)
{
    observers.emplace_back(observer);
    return 0;
}

int Subject::removeObserver(Observer* observer)
{
    std::vector<Observer*>::iterator it = std::find(observers.begin(), observers.end(), observer);
    if(it != observers.end())
    {
        observers.erase(it);
    }
    return 0;
}

int Subject::removeAll()
{
    observers.clear();
    return 0;
}

int Subject::showObservers()
{
    int len = observers.size();
    for(int i = 0; i < len; i++)
    {
        printf("observer para:%s\t", observers.at(i)->getPara().c_str());
    }
    std::cout<<std::endl;
    return 0;
}

News::News(){}

int News::getMessage(char& sex, int&age, std::string& name)
{
    std::vector<std::string> names;
    names.clear();
    names.emplace_back("Tom");
    names.emplace_back("Mike");
    names.emplace_back("Nancy");
    names.emplace_back("Joe");
    names.emplace_back("Jack");
    names.emplace_back("Bomb");
    names.emplace_back("Torky");
    names.emplace_back("Pipy");
    names.emplace_back("Lonr");
    names.emplace_back("Lucky User");
    int num = rand()%100;
    if(num < 50)
    {
        sex = 'F';
    }
    else
    {
        sex = 'M';
    }
    age = num;
    name = names.at(num%10);
    return 0;
}

int News::notifyObservers()
{
    int len = observers.size();
    if(!len)
    {
        std::cout<<"no observers in the subject news, break notify"<<std::endl;
        return 0;
    }
    char sex;
    int age;
    std::string name;
    News::getMessage(sex, age, name);
    for(int i = 0; i < len; i++)
    {
        observers.at(i)->update(sex, age, name);
    }
    return 0;
}

Observer::Observer()
{
    para = "";
}

std::string Observer::getPara()
{
    return para;
}

People::People()
{
    para = "default";
}

People::People(std::string para)
{
    this->para = para;
}

int People::update(char sex, int age, std::string name)
{
    this->age = age;
    this->sex = sex;
    this->name = name;
    printf("update sex:%c, age:%d, name:%s", sex, age, name.c_str());
    return 0;
}