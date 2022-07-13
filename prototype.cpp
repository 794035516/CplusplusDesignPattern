#include"include/prototype.h"
#include<iostream>
#include<assert.h>

int BeverageRecipeWithHook::prepareRecipe()
{
    boilWater();
    brew();
    pourInWater();
    addCondiments();
    return 0;
}

int BeverageRecipeWithHook::boilWater()
{
    std::cout<<"boil the water"<<std::endl;
    return 0;
}   

int BeverageRecipeWithHook::pourInWater()
{
    std::cout<<"pour the recipe into water"<<std::endl;
    return 0;
}

int CoffeeRecipe::brew()
{
    std::cout<<"brew the coffee"<<std::endl;
    return 0;
}

int CoffeeRecipe::addCondiments()
{
    std::cout<<"ask customer wheather add condiments or not(0: add, 1 not) : ";
    std::cin>>addFlag;
    assert(addFlag == 0 || addFlag == 1);
    if(addFlag == 0)
    {
        std::cout<<"add some condiments"<<std::endl;
    }
    return 0;
}

int TeaRecipe::brew()
{
    std::cout<<"brew the tea"<<std::endl;
    return 0;
}

int TeaRecipe::addCondiments()
{
    if(!addFlag)
    {
        std::cout<<"add some condiments"<<std::endl;
    }
    return 0;
}