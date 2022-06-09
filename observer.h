#ifndef _IOSTREAM_H_
#include<iostream>
#endif
#ifndef _VECTOR_H_
#include<vector>
#endif

class Observer
{
 public:
   virtual int update(char sex, int age, std::string name) = 0;
   virtual std::string getPara();

   Observer();
 protected:
   std::string para;
};

class People : public Observer
{
 public:
   People();
   People(std::string para);
   char getSex();
   int getAge();
   std::string getName();
   int update(char sex, int age, std::string name);

 protected:
   char sex;
   int age;
   std::string name;
};

class Subject
{
 public:
   virtual int registerObserver(Observer*);
   virtual int removeObserver(Observer*);
   virtual int removeAll();
   virtual int notifyObservers() = 0;
   int showObservers();

   Subject();

 protected:
   std::vector<Observer*> observers;
};

class News : public Subject
{
 public:
   News();

   int getMessage(char& sex, int& age, std::string& name);
   int notifyObservers();
};