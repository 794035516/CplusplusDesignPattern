#ifndef _IOSTREAM_H_
#include<iostream>
#endif
#ifndef _VECTOR_H_
#include<vector>
#endif

/*
observer get message from Subject through method update
*/
class Observer
{
 public:
 // get message
   virtual int update(char sex, int age, std::string name) = 0;
   virtual std::string getPara();

   Observer();
 protected:
  //specified data to distinguish observers
   std::string para;
};

/*
some message in the specific class
*/
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

/*
subject which can operate observers through register, remove, show and notify
*/
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

/*
include method: simulate the data to notify observers 
*/
class News : public Subject
{
 public:
   News();

   int getMessage(char& sex, int& age, std::string& name);
   int notifyObservers();
};