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
#include <list>
#include <deque>
#include <chrono>
#include <iomanip>



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

    //Listo rikiavimas
    if constexpr (std::is_same_v<konteineris, std::list<studentas>>)
    {
        switch(kriterijus)
        {
            case 1: A.sort(byVardas); break;
            case 2: A.sort(byPavarde); break;
            case 3: A.sort(byGalVid); break;
            case 4: A.sort(byGalMed); break;
        }
    }
    //Vector arba deque rikiavimas
    else
    {
        switch(kriterijus)
        {
            case 1: std::sort(A.begin(), A.end(), byVardas); break;
            case 2: std::sort(A.begin(), A.end(), byPavarde); break;
            case 3: std::sort(A.begin(), A.end(), byGalVid); break;
            case 4: std::sort(A.begin(), A.end(), byGalMed); break;
        }   
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

}

template<typename konteineris>
void KonteineriuTyrimas(konteineris& A, konteineris& vargsai, konteineris& kietekai, int kriterijus)
{
    std::vector<int> studKiekis = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << std::left << std::setw(12) << "Studentai" << std::setw(15) << "Skaitymas"
    << std::setw(15) << "Rikiavimas" << std::setw(15) << "skirstymas" 
    << std::setw(15) << "Bendras laikas" << std::endl;


    for(auto x : studKiekis)
    {
        //nuskaitymas
        auto start1 = std::chrono::high_resolution_clock::now();
        skaitymas(A, "studentai" + std::to_string(x) + ".txt");
        auto end1 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff1 = end1 - start1;

        //rikiavimas
        auto start2 = std::chrono::high_resolution_clock::now();
        rikiavimas(A, kriterijus);
        auto end2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff2 = end2 - start2;

        //i atskirus failus
        auto start3 = std::chrono::high_resolution_clock::now();
        StudentuPadalinimas(A, vargsai, kietekai, kriterijus);
        auto end3 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff3 = end3 - start3;

        //bendras
        double visas = diff1.count() + diff2.count() + diff3.count();

        std::cout << std::left << std::setw(12) << x << std::setw(15) << diff1.count()
        << std::setw(15) << diff2.count() << std::setw(15) << diff3.count() 
        << std::setw(15) << visas << std::endl;

        A.clear();
        vargsai.clear();
        kietekai.clear();


    }
}

#endif