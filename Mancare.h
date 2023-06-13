#ifndef MANCARE_H
#define MANCARE_H

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include "Persoana.h"

using namespace std;

class Mancare
{

private:
    vector<string> alimente;
    vector<int> calorii;
    vector<int> grasimi;
    vector<int> proteine;
    vector<int> carbohidrati;

    float numarportii = 0;
    int indexAliment = 0;


public:

    void citesteAlimente(char* filename)
    {
        ifstream file(filename);

        if (!file)
        {
            cout << "Eroare la deschiderea fisierului.\n";
            return;
        }

        while (!file.eof())
        {
            string linie;
            getline(file, linie);

            size_t pozitieDelimitator1 = linie.find(",");
            size_t pozitieDelimitator2 = linie.find(",",pozitieDelimitator1 +1);
            size_t pozitieDelimitator3 = linie.find(",", pozitieDelimitator2 +1);
            size_t pozitieDelimitator4 = linie.find(",", pozitieDelimitator3 +1);
            ///  cout<<"  wqf"<<pozitieDelimitator1;
            string aliment = linie.substr(0, pozitieDelimitator1);
            string caloriiStr = linie.substr(pozitieDelimitator1 + 1, pozitieDelimitator2 - pozitieDelimitator1 - 1);
            string grasimiStr = linie.substr(pozitieDelimitator2 + 1, pozitieDelimitator3 - pozitieDelimitator2 - 1);
            string proteineStr = linie.substr(pozitieDelimitator3 + 1,pozitieDelimitator4 - pozitieDelimitator3 - 1);
            string carbohidratiStr = linie.substr(pozitieDelimitator4 + 1);
            int calori = atoi(caloriiStr.c_str());
            int grasimii = atoi(grasimiStr.c_str());
            int proteini = atoi(proteineStr.c_str());
            int carbo = atoi(carbohidratiStr.c_str());

            alimente.push_back(aliment);
            calorii.push_back(calori);
            grasimi.push_back(grasimii);
            proteine.push_back(proteini);
            carbohidrati.push_back(carbo);
        }
        file.close();
    }


    bool citesteAlimentSiNrPortii()
    {
        string aliment;
        cin.ignore();

        while (true)
        {
            cout << "Introduceti alimentele pe care le-ati consumat(sau 'i' pentru a incheia): ";
            getline(cin,aliment);

            if (aliment == "i" || aliment == "I")
            {
                return false;
            }

            cout << "Numar portii(1 portie = 100 grame): ";
            cin >> numarportii;



            bool alimentGasit = false;
            for (size_t i = 0; i < alimente.size(); i++)
            {
                if (aliment == alimente[i])
                {
                    indexAliment = i;
                    return true;
                }
            }

            cout << "Alimentul " << aliment << " nu a fost gasit in fisier.\n";
            cin.ignore();
        }
    }

    int calculeazaCaloriiTotale()
    {
        return numarportii * calorii[indexAliment];
    }

    int calculeazaGrasimiTotale()
    {
        return numarportii * grasimi[indexAliment];
    }

    int calculeazaProteineTotale()
    {
        return numarportii * proteine[indexAliment];
    }

    int calculeazaCarboTotali()
    {
        return numarportii * carbohidrati[indexAliment];
    }
   /*/ void obiectivul(int numarActivitati, Persoana& persoana)
{
    int deficit;

    int necesarCaloric = persoana.necesarcaloric(numarActivitati);
    cout<<"fff"<<necesarCaloric;
    int consumcaloric = calculeazaCaloriiTotale();
    cout<<"ccc"<<consumcaloric;

    if (necesarCaloric >= consumcaloric)
    {
        deficit= necesarCaloric - consumcaloric;
        cout << "Mai puteti consuma " << deficit << " kilocalorii.\n";
    }
    else
    {
        deficit=  consumcaloric - necesarCaloric;
        cout << "Ati consumat cu " << deficit << " mai multe kilocalorii decat necesarul caloric.\n";
    }
}/*/

};



#endif // MANCARE_H
