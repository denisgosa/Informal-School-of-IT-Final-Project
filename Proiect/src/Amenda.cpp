#include "Amenda.h"

Amenda::Amenda()
{
    //ctor
}

Amenda::Amenda(short cod,string nume, int am,short cat,short codS)
{
    cod_agent = cod;
    newName = nume;
    amenda = am;
    categorie = cat;
    cod_sofer = codS;
}

void Amenda::setCod(short cod)
{
    cod_agent = cod;
}

void Amenda::setCodS(short cod)
{
    cod_sofer = cod;
}

void Amenda::setName(string nume)
{
    newName = nume;
}

void Amenda::setAmenda(int am)
{
    amenda = am;
}

void Amenda::setCat(short cat)
{
    categorie = cat;
}

Amenda::~Amenda()
{
    //dtor
}
