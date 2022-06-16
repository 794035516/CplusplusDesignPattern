#ifndef _VECTOR_
#include<vector>
#endif
#ifndef _STRING_
#include<string>
#endif

enum STATUS 
{
   ON,
   OFF
};

class Command
{
 public:
    virtual int run() = 0;
    virtual int undo() = 0;
};

class OnCommand : public Command
{
 public:
    virtual int run() = 0;
    virtual int undo() = 0;
};

class OffCommand : public Command
{
 public:
    virtual int run() = 0;
    virtual int undo() = 0;
};


class NoCommand : public Command
{
 public:
    NoCommand();
    virtual int run() ;
    virtual int undo();
};

class Light
{
 public:
   Light();
   Light(std::string name);
   int on() ;
   int off() ;
   STATUS getStatus();
   int setStatus(STATUS status);
    //int undo(); this func should not in this class
 private:
   std::string name;
   STATUS status;
};

class LightOnCommand : public OnCommand
{
 public:
    LightOnCommand(Light* light);
    virtual int run() ;
    virtual int undo();
 
 protected:
   Light* light;
};

class LightOffCommand : public OffCommand
{
 public:
    LightOffCommand(Light* light);
    virtual int run() ;
    virtual int undo();
 
 protected:
   Light* light;
};


class TV
{
 public:
   TV();
   TV(std::string name);
   int on() ;
   int off() ;
   STATUS getStatus();
   int setStatus(STATUS status);

 private:
   std::string name;
   STATUS status;
};

class TVOnCommand : public OnCommand
{
 public:
    TVOnCommand(TV* tv);
    virtual int run() ;
    virtual int undo();

 protected:
   TV* tv;
};

class TVOffCommand : public OffCommand
{
 public:
    TVOffCommand(TV* tv);
    virtual int run() ;
    virtual int undo();

 protected:
   TV* tv;
};


class Machine
{
 public:
   Machine();
   Machine(std::string name);
   int on() ;
   int off() ;
   STATUS getStatus();
   int setStatus(STATUS status);

 private:
   std::string name;
   STATUS status;
};

class MachineOnCommand : public OnCommand
{
 public:
   MachineOnCommand(Machine* machine);
   virtual int run() ;
   virtual int undo();

 protected:
   Machine* machine;
};

class MachineOffCommand : public OffCommand
{
 public:
   MachineOffCommand(Machine* machine);
   virtual int run() ;
   virtual int undo();

 protected:
   Machine* machine;
};


class Music
{
 public:
   Music();
   Music(std::string name);
   int on() ;
   int off() ;
   STATUS getStatus();
   int setStatus(STATUS status);

 private:
   std::string name;
   STATUS status;
};

class MusicOnCommand : public OnCommand
{
 public:
    MusicOnCommand(Music* music);
    virtual int run() ;
    virtual int undo();

 protected:
   Music* music;
};

class MusicOffCommand : public OffCommand
{
 public:
    MusicOffCommand(Music* music);
    virtual int run() ;
    virtual int undo();

 protected:
   Music* music;
};


//--

class MacroCommand : public Command
{
 public:
   virtual int run() = 0;
   virtual int undo() = 0;
};

class MusicParty 
{
 public:
   MusicParty();
   MusicParty(std::string partyName, Music* musicName, 
       Light* lightName, TV* tvName);
   STATUS getStatus();
   int setStatus(STATUS status);
   int on();
   int off();

 protected:
   std::string name;
   STATUS status;

   Music* music;
   Light* light;
   TV* tv;
};

class MusicPartyOnMacCMD : public MacroCommand
{
 public:
   MusicPartyOnMacCMD(MusicParty* musicParty);
   virtual int run();
    virtual int undo();

 private:
   MusicParty* musicParty;
};

class MusicPartyOffMacCMD : public MacroCommand
{
 public:
   MusicPartyOffMacCMD(MusicParty* musicParty);
   virtual int run();
    virtual int undo();

 private:
   MusicParty* musicParty;
};


class MovieParty 
{
 public:
   MovieParty();
   MovieParty(std::string macroName, Machine* machine, TV* tv, Light* light);
   STATUS getStatus();
   int setStatus(STATUS status);
   int on();
   int off();

 protected:
   std::string name;
   STATUS status;

   Machine* machine;
   TV* tv;
   Light* light;
};

class MoviePartyOnMacCMD : public MacroCommand
{
 public:
   MoviePartyOnMacCMD(MovieParty* movieParty);
   virtual int run();
    virtual int undo();

 private:
   MovieParty* movieParty;
};

class MoviePartyOffMacCMD : public MacroCommand
{
 public:
   MoviePartyOffMacCMD(MovieParty* movieParty);
   virtual int run();
    virtual int undo();

 private:
   MovieParty* movieParty;
};

