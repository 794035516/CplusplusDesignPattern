#include<iostream>
#include<map>
#include"include/runCPP.h"
int arr[] = {1, 2, 3};


int putMessage()
{
    std::cout<<"-----------------------------"<<std::endl;
    for(auto& it: RunCPP::getInstance()->getAllShowFuns())
    {
        printf("%d: run %s\n", it.first, it.second.c_str());
    }
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"input a number you want to rum the dessign pattern code: ";
    return 0;
}

int getMessage()
{
    int number = 0;
    std::cin>>number;
    int len = sizeof(arr);
    for(std::pair<int, std::string> it: RunCPP::getInstance()->getAllShowFuns())
    {
        if(it.first == number)
        {
            return number;
        }
    }
    return -1;
}

int main()
{
    RunCPP* runcpp = RunCPP::getInstance();
    while(true)
    {
        putMessage();
        int choose = getMessage();
        int flag = runcpp->getDoFuns(choose)();
        if(flag != 0)
        {
            break;
        }
    }
    return 0;
}