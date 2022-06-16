#ifndef _MAP_H_
#include<map>
#endif
#ifndef _FUNCTIONAL_
#include<functional>
#endif
#ifndef _STRATEGY_H_
#include"strategy.h"
#endif
#ifndef _OBSERVER_H_
#include"observer.h"
#endif
#ifndef _DECORATOR_H_
#include"decorator.h"
#endif
#ifndef _COMMAND_H_
#include"command.h"
#endif

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
