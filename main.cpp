#include<iostream>
#include"runCPP.h"
int arr[] = {1, 2};


int putMessage()
{
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"-1: quit the game"<<std::endl;
    std::cout<<" 1: strategy mode"<<std::endl;
    std::cout<<" 2: observer mode"<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"input a number you want to rum the dessign pattern code"<<std::endl;
    return 0;
}

void putError()
{
    std::cout<<"some error occur"<<std::endl;
    return ;
}

int getMessage()
{
    int number = 0;
    std::cin>>number;
    int len = sizeof(arr);
    for(int i=0; i<len; i++)
    {
        if(number == arr[i])
        {
            return number;
        }
    }
    return -1;
}

int main()
{

    while(true)
    {
        putMessage();
        int choose = getMessage();
        if(choose <= -1)
        {
            putError();
            break;
        }
        if(choose == 1)
        {
            RunCPP::runStrategy();
        }
        else if(choose == 2)
        {
            RunCPP::runObserver();
        }
    }

    return 0;
}