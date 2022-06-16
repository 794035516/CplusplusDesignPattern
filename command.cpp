#ifndef _COMMAND_H_
#include"include/command.h"
#endif

NoCommand::NoCommand(){}
int NoCommand::run() 
{
    return 0;
}
int NoCommand::undo() 
{
    return 0;
}

Light::Light()
{
    name = "missing light name";
    status = OFF;
}

Light::Light(std::string name)
{
    this->name = name;
    status = OFF;
}

int Light::on()
{
    printf("the light:%s turns on\n", name.c_str());
    status = ON;
    return 0;
}

int Light::off() 
{
    printf("the light:%s turns off\n", name.c_str());
    status = OFF;
    return 0;
}

STATUS Light::getStatus()
{
    return status;
}

int Light::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

LightOnCommand::LightOnCommand(Light* light)
{
    this->light = light;
}

int LightOnCommand::run() 
{
    light->on();
    return 0;
}

int LightOnCommand::undo()
{
    if(light->getStatus() == OFF)
    {
        light->on();
    }
    else
    {
        light->off();
    }
    return 0;
}

LightOffCommand::LightOffCommand(Light* light)
{
    this->light = light;
}

int LightOffCommand::run() 
{
    light->off();
    return 0;
}

int LightOffCommand::undo()
{
    if(light->getStatus() == OFF)
    {
        light->on();
    }
    else
    {
        light->off();
    }
    return 0;
}


TV::TV()
{
    name = "missing TV name";
    status = OFF;
}

TV::TV(std::string name)
{
    this->name = name;
    status = OFF;
}

int TV::on()
{
    printf("the TV:%s turns on\n",name.c_str());
    status = ON;
    return 0;
}

int TV::off()
{
    printf("the TV:%s turns off\n",name.c_str());
    status = OFF;
    return 0;
}

STATUS TV::getStatus()
{
    return status;
}

int TV::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

TVOnCommand::TVOnCommand(TV* tv)
{
    this->tv = tv;
}

int TVOnCommand::run()
{
    tv->on();
    return 0;
}

int TVOnCommand::undo()
{
    if(tv->getStatus() == ON)
    {
        tv->off();
    }
    else
    {
        tv->on();
    }
    return 0;
}

TVOffCommand::TVOffCommand(TV* tv)
{
    this->tv = tv;
}

int TVOffCommand::run()
{
    tv->off();
    return 0;
}

int TVOffCommand::undo()
{
    if(tv->getStatus() == ON)
    {
        tv->off();
    }
    else
    {
        tv->on();
    }
    return 0;
}

//---

Machine::Machine()
{
    name = "missing Machine name";
    status = OFF;
}

Machine::Machine(std::string name)
{
    this->name = name;
    status = OFF;
}

int Machine::on()
{
    printf("the Machine:%s turns on\n",name.c_str());
    status = ON;
    return 0;
}

int Machine::off()
{
    printf("the Machine:%s turns off\n",name.c_str());
    status = OFF;
    return 0;
}

STATUS Machine::getStatus()
{
    return status;
}

int Machine::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

MachineOnCommand::MachineOnCommand(Machine* machine)
{
    this->machine = machine;
}

int MachineOnCommand::run()
{
    machine->on();
    return 0;
}

int MachineOnCommand::undo()
{
    if(machine->getStatus() == ON)
    {
        machine->off();
    }
    else
    {
        machine->on();
    }
    return 0;
}

MachineOffCommand::MachineOffCommand(Machine* machine)
{
    this->machine = machine;
}

int MachineOffCommand::run()
{
    machine->off();
    return 0;
}

int MachineOffCommand::undo()
{
    if(machine->getStatus() == ON)
    {
        machine->off();
    }
    else
    {
        machine->on();
    }
    return 0;
}

//-------

Music::Music()
{
    name = "missing Music name";
    status = OFF;
}

Music::Music(std::string name)
{
    this->name = name;
    status = OFF;
}

int Music::on()
{
    printf("the Music:%s turns on\n",name.c_str());
    status = ON;
    return 0;
}

int Music::off()
{
    printf("the Music:%s turns off\n",name.c_str());
    status = OFF;
    return 0;
}

STATUS Music::getStatus()
{
    return status;
}

int Music::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

MusicOnCommand::MusicOnCommand(Music* music)
{
    this->music = music;
}

int MusicOnCommand::run()
{
    music->on();
    return 0;
}

int MusicOnCommand::undo()
{
    if(music->getStatus() == ON)
    {
        music->off();
    }
    else
    {
        music->on();
    }
    return 0;
}

MusicOffCommand::MusicOffCommand(Music* music)
{
    this->music = music;
}

int MusicOffCommand::run()
{
    music->off();
    return 0;
}

int MusicOffCommand::undo()
{
    if(music->getStatus() == ON)
    {
        music->off();
    }
    else
    {
        music->on();
    }
    return 0;
}


//--

MusicParty::MusicParty()
{
    name = "missing music party name";
    music = new Music();
    light = new Light();
    tv = new TV();
    status = OFF;
}

MusicParty::MusicParty(std::string partyName, Music* music, 
    Light* light, TV* tv)
{
    this->name = partyName;
    this->music = music;
    this->light = light;
    this->tv = tv;
    status = OFF;
}

STATUS MusicParty::getStatus()
{
    return status;
}

int MusicParty::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

int MusicParty::on()
{
    printf("music party on\n");
    music->on();
    light->off();
    tv->on();
    printf("\n");
    status = ON;
    return 0;
}

int MusicParty::off()
{
    printf("music party off\n");
    tv->off();
    light->on();
    music->off();
    printf("\n");
    status = OFF;
    return 0;
}

MusicPartyOnMacCMD::MusicPartyOnMacCMD(MusicParty* musicParty)
{
    this->musicParty = musicParty;
}

int MusicPartyOnMacCMD::run()
{
    musicParty->on();
    return 0;
}

int MusicPartyOnMacCMD::undo()
{
    if(musicParty->getStatus() == ON)
    {
        musicParty->off();
    }
    else
    {
        musicParty->on();
    }
    return 0;
}

MusicPartyOffMacCMD::MusicPartyOffMacCMD(MusicParty* musicParty)
{
    this->musicParty = musicParty;Music* music;
    Light* light;
    TV* tv;
}

int MusicPartyOffMacCMD::run()
{
    musicParty->off();
    return 0;
}

int MusicPartyOffMacCMD::undo()
{
    if(musicParty->getStatus() == ON)
    {
        musicParty->off();
    }
    else
    {
        musicParty->on();
    }
    return 0;
}


MovieParty::MovieParty()
{
    name = "missing movie party name";
    status = OFF;
    machine = new Machine();
    tv = new TV();
    light = new Light();
}

MovieParty::MovieParty(std::string name, Machine* machine, TV* tv, Light* light)
{
    this->name = name;
    this->machine = machine;
    this->tv = tv;
    this->light = light;
    status = OFF;
}

STATUS MovieParty::getStatus()
{
    return status;
}

int MovieParty::setStatus(STATUS status)
{
    this->status = status;
    return 0;
}

int MovieParty::on()
{
    printf("movie party on\n");
    light->off();
    machine->on();
    tv->on();
    printf("\n");
    status = ON;
    return 0;
}

int MovieParty::off()
{
    printf("movie party off: \n");
    tv->off();
    machine->off();
    light->on();
    printf("\n");
    status = OFF;
    return 0;
}

MoviePartyOnMacCMD::MoviePartyOnMacCMD(MovieParty* movieParty)
{
    this->movieParty = movieParty;
}

int MoviePartyOnMacCMD::run()
{
    movieParty->on();
    return 0;
}

int MoviePartyOnMacCMD::undo()
{
    if(movieParty->getStatus() == ON)
    {
        movieParty->off();
    }
    else
    {
        movieParty->on();
    }
    return 0;
}

MoviePartyOffMacCMD::MoviePartyOffMacCMD(MovieParty* movieParty)
{
    this->movieParty = movieParty;
}

int MoviePartyOffMacCMD::run()
{
    movieParty->off();
    return 0;
}


int MoviePartyOffMacCMD::undo()
{
    if(movieParty->getStatus() == ON)
    {
        movieParty->off();
    }
    else
    {
        movieParty->on();
    }
    return 0;
}
