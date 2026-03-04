#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "skaitymas.h"



void skaitymas(std::vector<studentas>& A, std::string failas)
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
        A.push_back(s);
    }
}

void skaitymoTestai(std::vector<studentas>& A, std::string failas)
{
    int kartai = 5;
    double bendras = 0.0;
    
    while(true)
    {
        std::cout << "Kuri faila nuskaityti testavimui?" << std::endl;
        std::cin >> failas;
        if(failas == "kursiokai.txt" || failas == "studentai10000.txt" || failas == "studentai100000.txt" || failas == "studentai1000000.txt")
        {
            break;
        }
        std::cout << "Bandykite ivest dar karta! " << std::endl;
    }

    for(int i = 0; i < kartai; i++)
    {
        A.clear();
        auto start = std::chrono::steady_clock::now();

        skaitymas(A, failas);

        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = end - start;
        bendras += diff.count();
    }

    std::cout << "failo " << failas << " nuskaitymo vidurkis: " << bendras / kartai << "s." << std::endl;
}
