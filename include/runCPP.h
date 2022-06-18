#pragma once
#include<map>
#include<functional>
#include"strategy.h"
#include"observer.h"
#include"decorator.h"
#include"command.h"
#include"adapter.h"

enum Mode
{
   STRATEGY = 1,
   OBSERVER,
   DECORATOR,
   COMMANDS,
   ADAPTER
};

/* 
run the program 
such as strategy mode, observer mode
*/
namespace RunSpace
{
    int runError();
    int runStrategy();
    int runObserver();
    int runDecorator();
    int runCommands();
    int runAdapter();
};

class RunCPP
{
 public:
    static RunCPP* getInstance();
    void setDoFuns(int num, std::function<int()>);
    void setShowFuns(int num, std::string);
    std::function<int()> getDoFuns(int num) const;
    std::string getShowFuns(int num) const; 
    std::map<int, std::string> getAllShowFuns() const;
    static RunCPP* singletonInstance;

 protected:
    std::map <int, std::function<int()>> doFuns;
    std::map <int, std::string > showFuns;

 private:
    RunCPP();
};
