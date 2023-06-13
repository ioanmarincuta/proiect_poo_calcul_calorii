#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>

using namespace std;

class Persoana
{
private:
    float inaltime;
    float masa;
    int varsta;
    char sex;

public:
    Persoana(float _inaltime, float _masa, char _sex, int _varsta)
    {
        this->inaltime = _inaltime;
        this->masa = _masa;
        this->sex=_sex;
        this->varsta=_varsta;
    }

    float getmasa()
    {
        return masa;
    }
    void setmasa(float _masa)
    {
        this->masa=_masa;
    }
    void setinaltime(float _inaltime)
    {
        this->inaltime=_inaltime;
    }
    float getinaltime()
    {
        return inaltime;
    }

    string getimc()
    {
        float imc = getmasa() / (getinaltime() * getinaltime());
        if(imc < 19)
            return " sunteti subponderal";
        else if(imc >= 19 && imc <= 25)
            return " aveti o masa normala";
        else if(imc >= 25 && imc < 30)
            return " sunteti supraponderal";
        else if(imc >= 30 && imc < 35)
            return " aveti obezitate grad I";
        else if(imc >= 35 && imc < 40)
            return " aveti obezitate grad II";
        else
            return " aveti obezitate grad III";
    }

    float necesarcaloric(int numarActivitati)
    {
        float rmb;

        if (sex == 'M')
        {
            rmb = 655 + (13.75 * masa) + (5 * inaltime ) - (6.78 * varsta);
        }
        else if (sex == 'F')
        {
            rmb = 655 + (9.56 * masa) + (1.85 * inaltime ) - (4.68 * varsta);
        }
        else
        {
            cout << "Sexul nu este specificat corect.\n";
        }

        float coeficient_activitati;

        if (numarActivitati >= 0 && numarActivitati <= 2)
        {
            if(sex == 'M')
                coeficient_activitati = 1.56;
            else if(sex == 'F')
                coeficient_activitati = 1.56;
        }
        else if(numarActivitati >=3  && numarActivitati <= 5)
        {
            if(sex== 'M')
                coeficient_activitati = 1.78;
            else if(sex== 'F')
                coeficient_activitati = 1.64;
        }
        else if(numarActivitati > 5)
        {
            if(sex == 'M')
                coeficient_activitati = 2.1;
            else if(sex == 'F')
                coeficient_activitati = 1.82;
        }
        else
        {
            cout << "Numarul de activitati nu este specificat corect.\n";
        }

        float necesarCaloricTotal = rmb * coeficient_activitati;
        ///cout << "Necesarul caloric total: " << necesarCaloricTotal << " calorii pe zi.\n";
        return necesarCaloricTotal;
    }
};


#endif // PERSOANA_H
