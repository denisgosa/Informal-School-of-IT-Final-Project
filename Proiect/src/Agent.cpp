#include "Agent.h"
#include <string>

Agent::Agent()
{
    newName = ' ';

}

Agent::Agent(string name, short cod)
{
    newName = name;
    cod_unic = cod;
}

void Agent::SetName(string name)
{
    newName = name;
}

void Agent::SetCod(short cod)
{
    cod_unic = cod;
}
Agent::~Agent()
{
    //dtor
}
