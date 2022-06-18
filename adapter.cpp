#include"include/adapter.h"
#include<stdio.h>

Turkey::Turkey()
{
    Animal();
}

int Turkey::show()
{
    printf("I am a turkey\n");
    return 0;
}

int Turkey::display()
{
    printf("I am a turkey\n");
    return 0;
}

DogAdapter::DogAdapter(Dog* dog)
{
    Turkey();
    this->dog = dog;
}

int DogAdapter::show()
{
    dog->display();
    return 0;
}


