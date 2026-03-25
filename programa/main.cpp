#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include "studentas.h"
#include "skaiciavimai.h"
#include "skaitymas.h"
#include "isvedimas.h"

const std::vector<std::string> vardai = {"Rokas", "Dziugas", "Kajus", "Dovydas", "Matas", "Simonas", "Mantas", "Kasparas", "Tomas", "Kristupas"};
const std::vector<std::string> pavardes = {"Brazdeikis" , "Kazlauskas", "Macijauskas", "Sabonis", "Valanciunas", "Tubelis", "Sirvydis", "Ulanovas", "Giedraitis", "Kalnietis"};


int main(){
    
    std::vector<studentas> A;
    std::vector<studentas> vargsai;
    std::vector<studentas> kietekai;
    srand(time(NULL));
    bool run = true;
    int auto_kiekis = -1;

    while(run)
    {
        std::cout << "Pasirinkimų meniu: " << std::endl;
        std::cout << "1 - Ivesti ranka; " << std::endl;
        std::cout << "2 - Generuoti tik pazymius; " << std::endl;
        std::cout << "3 - Generuoti studentu vardus, pavardes ir pazymius; " << std::endl;
        std::cout << "4 - Skaityti informacija is failo; " << std::endl;
        std::cout << "5 - Generuoti studentų failą; " << std::endl;
        std::cout << "6 - atlikti tyrimą" << std::endl;
        std::cout << "7 - Baigti darbą; " << std::endl;
        std::cout << " Pasirinkite ";
        int pasirinkimas;
        try{
            std::cin >> pasirinkimas;
            if(std::cin.fail())
            {
                throw std::invalid_argument("Įvestis nėra sveikasis skaičius. ");
            }
            if(pasirinkimas < 1 || pasirinkimas > 6) 
            {
                throw std::out_of_range("Pasirinkimas už leistino intervalo (1-5) ribų");
            }
        } catch(std::exception& e) {
            std::cout << "Klaida: " << e.what() << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        

        switch(pasirinkimas)
        {
            case 1: //ranka
            case 2: //auto nd ir egz
            {
                while(true)
                {
                    studentas s;
                    std::cout << "Iveskite " << A.size() + 1 << " studento varda ('pabaiga' - baigia ivedinejima): " << std::endl;
                    std::cin >> s.vardas;
                    if(s.vardas == "pabaiga")
                    {
                        break;
                    }

                    std::cout << "Iveskite studento pavarde: " << std::endl;
                    std::cin >> s.pavarde;

                    if(pasirinkimas == 1)
                    {
                        while(true)
                        {
                            int nd;
                            std::cout << "Iveskite " << A.size() + 1 << " studento " << s.nd.size() + 1 <<  " namu darbo ivertinima ( 0 - baigti): " << std::endl;
                            std::cin >> nd;
                            if(nd == 0)
                            {
                                break;
                            }

                            if(nd < 0 || nd > 10)
                            {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                std::cout << "Ivedete neteisingai, bandykite dar karta!" << std::endl;
                                continue;
                            }

                            s.nd.push_back(nd);

                        }
                    }
                    else if(pasirinkimas == 2)
                    {
                        if(auto_kiekis == -1)
                        {
                            std::cout << "Iveskite norima pazymiu kieki: " << std::endl;
                            std::cin >> auto_kiekis;
                        }
                        for(int i = 0; i < auto_kiekis; i++)
                        {
                            s.nd.push_back(rand() % 10 + 1);
                        }
                    }

                    if(pasirinkimas == 1)
                    {
                        while(true)
                        {
                        std::cout << "Iveskite " << A.size() + 1 << " studento egzamino rezultata: " << std::endl;
                        std::cin >> s.egzaminas;
                        if(s.egzaminas > 0 && s.egzaminas <= 10)
                        {
                            break;
                        }
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Ivedete neteisingai, bandykite dar karta!" << std::endl;
                        }
                    }
                    else if(pasirinkimas == 2)
                    {
                        s.egzaminas = rand() % 10 + 1;
                    }

                    s.galutinisVid = galutinis(s, vidurkis(s));
                    s.galutinisMed = galutinis(s, mediana(s));

                    A.push_back(s);

                }
                break;
            }
            case 3:
            {
                int m;
                int n;
                std::cout << "Kiek studentu sugeneruoti? " << std::endl;
                while(true)
                {
                    std::cin >> m;
                    if(m >= 0)
                    {
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Ivedete neteisingai, bandykite dar karta! " << std::endl;
                }
                std::cout << "Kiek pazymiu sugeneruoti? " << std::endl;
                std::cin >> n;
                for(int i = 0; i < m; i++)
                {
                    studentas s;
                    s.vardas = vardai[rand() % vardai.size()];
                    s.pavarde = pavardes[rand() % pavardes.size()];
                    s.egzaminas = rand() % 10 + 1;
                    if(m > 0)
                    {
                        for(int i = 0; i < n; i++)
                        {
                            s.nd.push_back(rand() % 10 + 1);
                        }
                    }

                    s.galutinisVid = galutinis(s, vidurkis(s));
                    s.galutinisMed = galutinis(s, mediana(s));
                    
                    A.push_back(s);
                }
                break;
            }
            case 4:
            {
                bool tinka = true;
                while(tinka)
                {
                    std::string failas;
                    std::cout << "Pasirinkite faila: " <<std::endl;
                    std::cout << "kursiokai.txt , studentai10000.txt, studentai100000.txt, studentai1000000.txt" << std::endl;
                    std::cin >> failas;
                    try{
                        skaitymas(A, failas);
                        tinka = false;
                    } catch(std::exception& e) {
                        std::cout << "Klaida: " << e.what() << std::endl;
                        std::cout<< "Bandykite dar karta!" << std::endl;
                    }

                }
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
                rikiavimas(A,kriterijus);
                failoSpausdinimas(A);
                skaitymoTestai(A, "studentai1000000.txt");
                run = false;
                break;
            }
            case 5:
            {
            
            int kiekis;
            while(true)
            {
                std::cout << "Įveskite kiek studentų norite turėti faile: " << std::endl;
                std::cin >> kiekis;
                if(kiekis > 0)
                {
                    break;
                }
            }
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
            failoGeneravimas(kiekis);
            skaitymas(A, "studentai" + std::to_string(kiekis) + ".txt");
            StudentuPadalinimas(A, vargsai, kietekai, kriterijus);
            atskiriFailai("studentai" + std::to_string(kiekis) + ".txt", vargsai, kietekai);
            break;
            }

            case 6:
            {
                int tyrimas;
                while(true)
                {
                    std::cout << "Kurį tyrimą norite atlikti (1 arba 2): " <<std::endl;
                    std::cin >> tyrimas;
                    if(tyrimas == 1 || tyrimas == 2)
                    {
                        break;
                    }
                }

                if(tyrimas == 1)
                {
                    tyrimasPirmas();
                }
                else
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
                    tyrimasAntras(A, vargsai, kietekai, kriterijus);
                }


                break;

            }
            
            case 7:
            {
                spausdinimas(A);
                run = false;
                break;
            }
            default:
            {
                std::cout << "Ivedete neteisingai, bandykite dar karta! " << std::endl;
                break;
            }
        }

    }
    return 0;
}
