
#include <iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>

#include "Mancare.h"
#include "Persoana.h"

using namespace std;

int main()
{
    float inaltime;
    float masa;
    char sex;
    int numarActivitati;
    float varsta;

    cout << "Introduceti inaltimea (metri) uitlizand separatorul . : ";
    cin >> inaltime;

    if(inaltime>10 || inaltime<0)
    {
        cout<<"Inaltimea introdusa nu este valida"<<endl;
        cout << "Reintroduceti inaltimea (metri): ";
        cin>>inaltime;
    }

    cout << "Introduceti masa (kilograme): ";
    cin >> masa;

    cout << "Introduceti sexul (M/F): ";
    cin >> sex;

    if (sex != 'M' && sex != 'F')
    {
        cout << "Sexul introdus nu este valid"<<endl;
        cout <<"Reintroduceti sexul:";
        cin>>sex;
    }

    cout << "Introduceti varsta: ";
    cin>>varsta;

    Persoana persoana(inaltime, masa, sex, varsta);

    cout<<"In acest moment"<<persoana.getimc()<<endl;

    cout << "Introduceti numarul de activitati fizice pe saptamana: ";
    cin >> numarActivitati;
    float necesarCaloricTotal = persoana.necesarcaloric(numarActivitati);

    string obiectiv;
    cout << "Introduceti obiectivul (slabire/mentinere/crestere): ";
    cin >> obiectiv;

    if (obiectiv == "slabire")
    {
        necesarCaloricTotal *= 0.8;
    }
    else if (obiectiv == "crestere")
    {
        necesarCaloricTotal *= 1.2;
    }

    cout << "Necesarul caloric total: " << necesarCaloricTotal << " calorii pe zi.\n";

    ///  string filename = "alimente.txt";

    vector<Mancare> alimenteConsumate;

    // Citire alimente
    while(true)
    {
        Mancare mancare;
        mancare.citesteAlimente("alimente.txt");

        if(mancare.citesteAlimentSiNrPortii())
        {
            alimenteConsumate.push_back(mancare);
        }

        else
        {
            break;
        }
    }

    int caloriiTotale = 0;
    int grasimiTotale = 0;
    int proteineTotale = 0;
    int carboTotale = 0;

    for(int j = 0; j < alimenteConsumate.size(); j++)
    {
        caloriiTotale += alimenteConsumate[j].calculeazaCaloriiTotale();
        grasimiTotale += alimenteConsumate[j].calculeazaGrasimiTotale();
        proteineTotale += alimenteConsumate[j].calculeazaProteineTotale();
        carboTotale += alimenteConsumate[j].calculeazaCarboTotali();
    }

    cout << "Numarul total de kilocalorii consumate: " << caloriiTotale << endl;
    cout << "Numarul total de grasimi consumate: " << grasimiTotale << endl;
    cout << "Numarul total de proteine consumate: " << proteineTotale << endl;
    cout << "Numarul total de carbo consumati: " << carboTotale << endl;
   /// Mancare mancare;
   ///mancare.obiectivul(numarActivitati, persoana);
    return 0;
}
