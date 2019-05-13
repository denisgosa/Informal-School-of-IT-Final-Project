#ifndef SOFER_H
#define SOFER_H
#include <string>
#include <iostream>
#include "Agent.h"
using namespace std;
class Amenda
{
public:
    Amenda();
    Amenda(short,string,int,short,short);
    string getName(){return newName;};
    int getAmenda(){return amenda;};
    short getCat(){return categorie;};
    short getAgent(){return cod_agent;};
    short getCodS(){return cod_sofer;};
    void setCod(short);
    void setCodS(short);
    void setName(string);
    void setAmenda(int);
    void setCat(short);
    virtual ~Amenda();

protected:

private:
    short cod_agent,cod_sofer;
    string newName;
    int amenda;
    short categorie;

};

#endif // SOFER_H
