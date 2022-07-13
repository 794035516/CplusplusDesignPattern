#pragma once

class BeverageRecipeWithHook
{
 public:
    int prepareRecipe();
    bool addFlag = false;

 protected:
    int boilWater();
    virtual int brew() = 0;
    int pourInWater();
    virtual int addCondiments() = 0;

};

class CoffeeRecipe : public BeverageRecipeWithHook
{
 protected:
    virtual int brew();
    virtual int addCondiments();
};

class TeaRecipe : public BeverageRecipeWithHook
{
 protected:
    virtual int brew();
    virtual int addCondiments();
};

