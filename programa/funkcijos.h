#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>



double vidurkis(const studentas& A);
double mediana(const studentas& A);
double galutinis(const studentas& A, double balai);
void spausdinimas(std::vector<studentas>& A);
void failoSpausdinimas(std::vector<studentas>& A);
void failoGeneravimas(int studKiekis);
void atskiriFailai(std::string failas, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void tyrimasPirmas();
void tyrimasAntras(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai, int kriterijus);

template<typename konteineris> 
void skaitymas(konteineris& A, std::string failas)
{
    std::ifstream input(failas);

    if(!input.is_open())
    {
        throw std::runtime_error("Pasirinkto failo nepavyko atidaryti!");
    }
    std::string eilute;

    getline(input, eilute);

    while(getline(input, eilute))
    {
        std::stringstream ss(eilute);
        studentas s;
        ss >> s.vardas >> s.pavarde;

        std::vector<int> pazymiai;
        int x;
        while(ss >> x)
        {
            pazymiai.push_back(x);
        }

        s.egzaminas = pazymiai.back();
        pazymiai.pop_back();


        s.nd = pazymiai;
        s.galutinisVid = galutinis(s, vidurkis(s));
        s.galutinisMed = galutinis(s, mediana(s));

        A.push_back(s);
    }
}

template<typename konteineris>
void rikiavimas(konteineris& A, int kriterijus)
{
    
    auto byVardas = [](const studentas& a, const studentas& b)
    {
        return a.vardas < b.vardas;
    };
    auto byPavarde = [](const studentas& a, const studentas& b)
    {
        return a.pavarde < b.pavarde;
    };
    auto byGalVid = [](const studentas& a, const studentas& b)
    {
        return a.galutinisVid < b.galutinisVid;
    };
    auto byGalMed = [](const studentas& a, const studentas& b)
    {
        return a.galutinisMed < b.galutinisMed;
    };
    
    
    switch(kriterijus)
    {
        case 1: std::sort(A.begin(), A.end(), byVardas); break;
        case 2: std::sort(A.begin(), A.end(), byPavarde); break;
        case 3: std::sort(A.begin(), A.end(), byGalVid); break;
        case 4: std::sort(A.begin(), A.end(), byGalMed); break;
    }

}

template<typename konteineris>
void StudentuPadalinimas(const konteineris& A, konteineris& vargsai, konteineris& kietekai, int kriterijus)
{
    for(const auto& s : A)
    {
        if(s.galutinisVid < 5.0)
        {
            vargsai.push_back(s);
        }
        else
        {
            kietekai.push_back(s);
        }
    }
    rikiavimas(vargsai, kriterijus);
    rikiavimas(kietekai, kriterijus);

}

#endif