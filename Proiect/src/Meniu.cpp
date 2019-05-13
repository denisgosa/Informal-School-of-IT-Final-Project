#include "Meniu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;


Meniu::Meniu()
{
    //ctor
}

void Meniu::AfiseazaEcranPrincipal()
{
    IncarcaDateA(ListaAgenti);
    IncarcaDateS(ListaSoferi);
    int selectie = -1;
    while (selectie != 0)
    {
        AfisareTabel(ListaSoferi,ListaAgenti);
        cout << "     MENU" << endl;
        cout << "\n1. Adaugare agent" << endl;
        cout << "2. Sterge agent" << endl;
        cout << "3. Adauga amenda" << endl;
        cout << "4. Afiseaza date agent" << endl;
        cout << "5. Afiseaza amenzi sofer" << endl;
        cout << "0. Iesire" << endl;
        cin >> selectie;
        switch(selectie)
        {

            case 1:
            {
                AfisareTabel(ListaSoferi,ListaAgenti);
                int selectie = -1;
                while(selectie != 0)
                {
                    string name;
                    cout<<"Introduceti numele Agentului:";
                    cin>>name;
                    fillVectorA(ListaAgenti,name);
                    cout << "\n1.Adaugare alt agent" << endl;
                    cout << "0.Iesire" <<endl;
                    cin >> selectie;
                }
            }
            break;
            case 2:
            {
                int code;
                    int selectie = -1;
                    while(selectie != 0)
                    {
                        AfisareTabel(ListaSoferi,ListaAgenti);
                        cout << "Introduceti codul agentului pe care vreti sa il stergeti: ";
                        do
                        {
                            cin>>code;
                        }while(!VerificareAgent(ListaAgenti,code));
                        deleteVectorA(ListaAgenti,code);
                        int cv=0,cs=0;
                        ListaSoferi.erase(
                                          remove_if(
                                                         ListaSoferi.begin(),
                                                         ListaSoferi.end(),
                                                         [&code](Amenda& p)
                                                            {
                                                                return p.getAgent() == code; }
                                                    ),
                                        ListaSoferi.end()
                                        );
                        AfisareTabel(ListaSoferi,ListaAgenti);
                        cout << "\n1.Stergere alt agent" << endl;
                        cout << "0.Iesire" << endl;
                        cin>>selectie;
                    }
            }
            break;

            case 3:
            {
                fillVectorS(ListaSoferi,ListaAgenti);
            }
            break;

            case 4:
            {
                int code;
                int selectie = -1;
                while(selectie != 0)
                {
                    AfisareTabel(ListaSoferi,ListaAgenti);
                    cout<<"Introduceti codul agentului pentru detalii:" << endl;
                    do
                    {
                        cin>>code;
                    }while(!VerificareAgent(ListaAgenti,code));
                    AfisareTabel(ListaSoferi,ListaAgenti);
                    int suma = 0,nr_am = 0;
                        for(auto j = ListaSoferi.begin() ; j != ListaSoferi.end() ; j++)
                        {
                            if(code == j->getAgent())
                            {
                                suma += j->getAmenda();
                                nr_am++;
                            }
                        }
                    if(suma)
                        cout << "\nAgentul a dat " << nr_am << " amenzi in valoare totala de " << suma << endl;
                    else
                        cout << "\nAgentul nu a dat amenzi " << endl;
                    cout << "\n1.Alege alt agent" << endl;
                    cout << "0.Iesire" <<endl;
                    cin >> selectie;
                }
            }break;
            case 5:{
                string ns;
                int selectie = -1;
                while(selectie != 0)
                {
                    short ct = 0;
                    int sum = 0;
                    AfisareTabel(ListaSoferi,ListaAgenti);
                    cout<<" Introduceti numele soferului: " << endl;
                    cin>>ns;
                    for(auto it = ListaSoferi.begin() ; it != ListaSoferi.end() ; it++)
                    {
                        if( (it)->getName() == ns)
                        {
                            ct++;
                            cout<< "Nume: " << it->getName()<< "    Amenda: " << it->getAmenda() << " RON    Categoria: "<< VerificareCat( it -> getCat()) << "    (CA: " << it->getAgent() << ")" <<endl;
                            sum += it -> getAmenda();
                        }
                    }
                    switch(ct)
                    {
                        case 0:{ cout<<"\nSoferul nu are amenzi!"<<endl;}break;
                        case 1:{ cout<<"\nSoferul are o amenda in valoare de " << sum <<endl;}break;
                        default :{cout<<"\nSoferul are "<<ct<<" amenzi in valoare de " << sum << endl;}break;
                    }
                    cout << "\n1.Alt sofer" << endl;
                    cout << "0.Iesire" <<endl;
                    cin>>selectie;
                }
            }
            case 0:{
            }break;
            default:
            {
                cout << "Alegeti o optiune intre 0 si 5:" << endl;
            }
        }
    }
    DescarcaDateA(ListaAgenti);
    DescarcaDateS(ListaSoferi);
}

void Meniu::fillVectorA(vector<Agent>& ParClass,string nume)
{
    cod += 1;
    Agent newAgent(nume, cod);
    ParClass.push_back(newAgent);
    cout << "\nAgentul a fost adaugat cu succes!" <<endl;
}

void Meniu::printVectorA(vector<Agent>& ParClass)
{
    for(auto it = ParClass.begin() ; it != ParClass.end() ; ++it)
    {
        cout<<"Nume: "<< it->getName() << "  Cod: " << it->getCodA() << endl;
    }
    cout<<endl;
}

void Meniu::deleteVectorA(vector<Agent>& ParClass, int cod)
{
    for(auto it = ParClass.begin() ; it != ParClass.end() ; ++it)
        if((it)->getCodA() == cod)
            {
                ParClass.erase(it);
                AfisareTabel(ListaSoferi,ListaAgenti);
                break;
            }
}

void Meniu::fillVectorS(vector<Amenda>& ParClass,vector<Agent>& Par2Class)
{
    string nume;
    short cat = -1,coda;
    int amenda;
    int selectie = -1;
    while(selectie != 0)
    {
        int par = 0;
        AfisareTabel(ListaSoferi,ListaAgenti);
        codS += 1;
        cout << "Adauga numele contravenientului: ";
        cin >> nume;
        cout << "Selectati categoria:" << endl;
        cout << "1.Bicicleta" << endl;
        cout << "2.Motoreta-motocicleta" <<endl;
        cout << "3.Autoturism" << endl;
        cout << "4.Camion" << endl;
        cout << "5.Tractor" << endl;
        cin >> cat;
        AfisareTabel(ListaSoferi,ListaAgenti);
        cout << "Precizati valoarea amenzii:" << endl;
        cin >> amenda;
        AfisareTabel(ListaSoferi,ListaAgenti);
        cout << "Selectati codul agentul constatator: " <<endl;
        printVectorA(Par2Class);
        do
        {
            cin>>coda;
        }
        while(!VerificareAgent(Par2Class,coda));
            for(auto it = Par2Class.begin() ; it != Par2Class.end() ; ++it)
            {
                if((it)->getCodA() == coda)
                {
                    Amenda newSofer(coda,nume,amenda,cat,codS);
                    ParClass.push_back(newSofer);
                    cout << "Amenda inregistrata!" << endl;
                }
            }
            cout << "\n1.Adauga alt contravenient" << endl;
            cout << "0.Iesire" << endl;
            cin >> selectie;
    }
}

void Meniu::printVectorS(vector<Amenda>& ParClass)
{
    for(auto it = ParClass.begin() ; it != ParClass.end() ; ++it)
    {
        cout<< "Nume: " << it->getName()<< "    Amenda: " << it->getAmenda() << " RON    Categoria: "<< VerificareCat( it -> getCat()) << "    (CA: " << it->getAgent() << ")" <<endl;
    }
    cout << "\nCA = cod agent constatator" << endl;
}

string Meniu::VerificareCat(short cat)
{
    switch(cat)
    {
        case 1:{ return " Bicicleta "; }
        case 2:{ return " Moped-Motocicleta "; }
        case 3:{ return " Autoturism "; }
        case 4:{ return " Camion "; }
        case 5:{ return " Tractor "; }
    }
}

bool Meniu::VerificareAgent(vector<Agent>& ParClass, short cod)
{
    for(auto it = ParClass.begin() ; it != ParClass.end() ; ++it)
        if((it)->getCodA() == cod)
            return true;
    cout<<"Agentul nu exista! Introduceti alt cod:";
    return false;
}

void Meniu::IncarcaDateA(vector<Agent>& Clasa_Par)
{
    ifstream inFile;
    string nume;
    short code;
    inFile.open("Date Agenti.txt");
    if(inFile.fail())
    {
        cerr << "Eroare la deschiderea fisierului Agenti!" << endl;
        //exit(1);
    }
    while(!inFile.eof())
    {
        inFile >> nume >> code;
        Agent newAgent(nume, code);
        Clasa_Par.push_back(newAgent);
    }
    inFile.close();
    cod = code;
}

void Meniu::IncarcaDateS(vector<Amenda>& Clasa_Par)
{
    ifstream inFile;
    string nume;
    short cod_a,cod_s,cat;
    int amenda;
    inFile.open("Date Soferi.txt");
    if(inFile.fail())
    {
        cerr << "Eroare la deschiderea fisierului Soferi!" << endl;
        //exit(1);
    }
    while(!inFile.eof())
    {
        inFile >> nume >> cod_a >> cod_s >> amenda >> cat;
        Amenda newSofer(cod_a,nume,amenda,cat,cod_s);
        Clasa_Par.push_back(newSofer);
    }
    inFile.close();
    codS = cod_s;
}

void Meniu::DescarcaDateA(vector<Agent>& Clasa_Par)
{
    ofstream myfile;
    myfile.open("Date Agenti.txt");
    for(auto i = Clasa_Par.begin() ; i != Clasa_Par.end()-1 ; i++)
        myfile << i->getName() << " " << i->getCodA() << " ";
    myfile << Clasa_Par.back().getName()<< " " << Clasa_Par.back().getCodA();
    myfile.close();
}

void Meniu::DescarcaDateS(vector<Amenda>& Clasa_Par)
{
    ofstream fisier;
    fisier.open("Date Soferi.txt");
    for(auto i = Clasa_Par.begin() ; i != Clasa_Par.end()-1 ; i++)
        fisier << i->getName() << " " << i->getAgent() << " " << i-> getCodS() << " " << i->getAmenda() << " " << i->getCat() << endl;
    fisier << Clasa_Par.back().getName() << " " << Clasa_Par.back().getAgent() << " " << Clasa_Par.back().getCodS() << " " << Clasa_Par.back().getAmenda() << " " << Clasa_Par.back().getCat();
    fisier.close();
}

void Meniu::AfisareTabel(vector<Amenda>& Vector1,vector<Agent>& Vector2)
{
    system("CLS");
    cout << "                              AGENTI" << endl << endl;
    printVectorA(ListaAgenti);
    cout << "________________________________________________________________________" << endl;
    cout << "                              AMENZI" << endl << endl;
    printVectorS(ListaSoferi);
    cout << "________________________________________________________________________" << endl;
    cout<<endl;
}

Meniu::~Meniu()
{
    //dtor
}
