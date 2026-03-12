#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "skaiciavimai.h"
#include "isvedimas.h"



void rikiavimas(std::vector<studentas>& A)
{
    int kriterijus;
    while(true)
    {
        std::cout << "Pagal ka rikiuoti? " << std::endl;
        std::cout << " 1 - varda " << std::endl;
        std::cout << " 2 - pavarde " << std::endl;
        std::cout << " 3 - Galutni (vidurkis) " << std::endl;
        std::cout << " 4 - Galutini (mediana) " << std:: endl;
        std::cin >> kriterijus;
        if(kriterijus == 1 || kriterijus == 2 || kriterijus == 3 || kriterijus == 4)
        {
            break;
        }
        std::cout << "Ivedete neteisingai, bandykite dar karta! " << std::endl;
    }
    switch(kriterijus)
    {
        case 1: 
        {
            std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b)
        {
            return a.vardas < b.vardas;
        });
        break;
        }
        case 2:
        {
            std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b)
        {
            return a.pavarde < b.pavarde;
        });
        break;
        }
        case 3:
        {
            std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b)
        {
            return a.galutinisVid < b.galutinisVid;
        });
        break;
        }
        case 4:
        {
            std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b)
        {
            return a.galutinisMed < b.galutinisMed;
        });
        break;
        }


    }

}

void spausdinimas(std::vector<studentas>& A)
{
    char budas;
    while(true)
    {
        std::cout << "Skaiciuoti pagal vidurki (v) ar mediana (m)? " << std::endl;
        std::cin >> budas;
        budas = tolower(budas);
        if(budas == 'v' || budas == 'm')
        {
            break;
        }
        std::cout << "Ivedete neteisingai, iveskite (v) arba (m)" << std::endl;
    }
    std::cout << std::left << std::setw(10) << "Vardas" << std::setw(10) << "Pavarde";
    
    if(budas == 'm')
    {
        std::cout << std::setw(20) << "Galutinis (Med.)" << std::endl;
    }
    else
    {
        std::cout << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    }
    
    std::cout << "------------------------------------------" << std::endl;

    for(auto& s : A)
    {
        std::cout <<std::setw(10) <<  s.vardas << std::setw(15)<< s.pavarde;
        if(budas == 'm')
        {
            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << std::endl;
        }
        else
        {
            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::endl;
        }
    } 
}

void failoSpausdinimas(std::vector<studentas>& A)
{
    char isvedimas;
    while(true)
    {
        std::cout << "Isvesti ekrane ar faile? (e) - ekrane, (f) - faile " << std::endl;
        std::cin >> isvedimas;
        if(isvedimas == 'e' || isvedimas == 'f')
        {
            break;
        }
        std::cout << "Ivedete neteisingai, bandykite dar karta! " << std::endl;
    }
    if(isvedimas == 'e')
    {
        std::cout << std::left << std::setw(10) << "Vardas" << std::setw(10) << "Pavarde"
    << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;

    
    for(auto& s : A)
    {
        std::cout << std::setw(10) << s.vardas << std::setw(15) << s.pavarde;

        std::cout << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << std::endl;
        
    }
    }
    else
    {
        std:: ofstream failas("rezultatai.txt");
        failas << std::left << std::setw(15) << "Vardas" << std::setw(20) << "Pavarde"
    << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;

    failas << "--------------------------------------------------------------" << std::endl;

    
    for(auto& s : A)
    {
        failas << std::setw(15) << s.vardas << std::setw(20) << s.pavarde;

        failas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << std::endl;
        
    }
    std::cout << "Rezultatai isvesti faile pavadinimu 'rezultatai.txt'" << std::endl;
    }

}

void failoGeneravimas(int studKiekis) {
    
    int pazymiuKiekis = 10;
    std::string failas = "studentai" + std::to_string(studKiekis) + ".txt";
    std::ofstream out(failas);

    for(int i = 1; i <= studKiekis; i++)
    {
        out << "VardasNR" << i << " " << "PavardeNR" << i << " ";

        for(int j = 0; j < pazymiuKiekis; j++)
        {
            out << (rand() % 10 + 1) << " ";
        }
        out << (rand() % 10 + 1) << "\n";
    }
}
