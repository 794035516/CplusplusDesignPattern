#pragma once
#include"strategy.h"

class Turkey : public Animal
{
 public:
    Turkey();
    virtual int show();
    virtual int display();
};

class DogAdapter : public Turkey
{
 public:
    DogAdapter(Dog* dog);
    virtual int show();
 private:
    Dog* dog;
};

