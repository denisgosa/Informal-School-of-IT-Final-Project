#ifndef MENIU_H
#define MENIU_H

#include <vector>

#include "Agent.h"
#include "Amenda.h"

class Meniu
{
public:
    Meniu();
    void AfiseazaEcranPrincipal();
    void IncarcaDateA(vector<Agent>&);
    void DescarcaDateA(vector<Agent>&);
    void IncarcaDateS(vector<Amenda>&);
    void DescarcaDateS(vector<Amenda>&);
    virtual ~Meniu();
protected:

private:
    void fillVectorA(vector<Agent>&,string);
    void printVectorA(vector<Agent>&);
    void deleteVectorA(vector<Agent>&,int);
    void fillVectorS(vector<Amenda>&,vector<Agent>&);
    void printVectorS(vector<Amenda>&);
    void deleteVectorS(vector<Amenda>&,int);
    bool VerificareAgent(vector<Agent>&,short);
    string VerificareCat(short);
    bool VerificareSofer(vector<Amenda>&, string,short,short);
    void AfisareTabel(vector<Amenda>& , vector<Agent>&);
    short cod = 0,codS = 0;
    vector<Agent> ListaAgenti;
    vector<Amenda> ListaSoferi;
};

#endif // MENIU_H
