#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>

using namespace std;

class Agent
{
public:
    Agent(); //Default Constructor
    Agent(string, short);
    virtual ~Agent();
    string getName()
    {
        return newName;
    }
    short getCodA()
    {
        return cod_unic;
    }
    void SetName(string);
    void SetCod(short);
protected:

private:
    string newName;
    short cod_unic;
};

#endif // AGENT_H
