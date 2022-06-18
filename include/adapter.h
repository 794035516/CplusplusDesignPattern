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

<<<<<<< HEAD
/*
facade mode is similar to the macro command ,so we can refer it 
*/

=======
>>>>>>> 8e3d7339c05d64bdd46e3af0f70f34c61eb01523
