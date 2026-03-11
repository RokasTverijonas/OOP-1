#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>

const std::vector<std::string> vardai = {"Rokas", "Dziugas", "Kajus", "Dovydas", "Matas", "Simonas", "Mantas", "Kasparas", "Tomas", "Kristupas"};
const std::vector<std::string> pavardes = {"Brazdeikis" , "Kazlauskas", "Macijauskas", "Sabonis", "Valanciunas", "Tubelis", "Sirvydis", "Ulanovas", "Giedraitis", "Kalnietis"};

struct studentas{
    std::string vardas, pavarde;
    std::vector<int> nd;
    int egzaminas;
};

double vidurkis(const studentas& A)
{
    if(A.nd.empty())
    {
        return 0.0;
    }
    double suma = 0;
    for(int i = 0; i < A.nd.size(); i++)
    {
        suma += A.nd[i];
    }
    double vidurkis = suma / A.nd.size();

    return vidurkis;
}

double mediana(const studentas& A)
{
    if(A.nd.empty())
    {
        return 0.0;
    }
    std::vector<int> temp = A.nd;
    std::sort(temp.begin(), temp.end());

    int n = temp.size(); 

    double rez;
    if(n % 2 != 0)
    {
        rez = temp[n / 2];
    }
    else
    {
        rez = (temp[n / 2] + temp[(n - 1) / 2]) / 2.0;
    }
    return rez;

}

double galutinis(const studentas& A, double balai)
{
    return 0.4 * balai + 0.6 * A.egzaminas;
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
        double nd_rez;
        if(budas == 'm')
        {
            nd_rez = mediana(s);
        }
        else
        {
            nd_rez = vidurkis(s);
        }
        double galutinis_rez = galutinis(s, nd_rez);
        std::cout <<std::setw(10) <<  s.vardas << std::setw(15)<< s.pavarde << std::setw(20) << std::fixed << std::setprecision(2) << galutinis_rez << std::endl;
    } 
}
void skaitymas(std::vector<studentas>& A, std::string failas)
{
    std::ifstream input(failas);

    if(!input.is_open())
    {
        std::cout << "Nepavyko atyidaryti failo!" << std::endl;
        return;
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
    input.close();
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

        std::cout << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, vidurkis(s)) << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, mediana(s)) << std::endl;
        
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

        failas << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, vidurkis(s)) << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, mediana(s)) << std::endl;
        
    }
    std::cout << "Rezultatai isvesti faile pavadinimu 'rezultatai.txt'" << std::endl;
    }

}

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
            return galutinis(a, vidurkis(a)) < galutinis(b, vidurkis(b));
        });
        break;
        }
        case 4:
        {
            std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b)
        {
            return galutinis(a, mediana(a)) < galutinis(b, mediana(b));
        });
        break;
        }


    }

}


int main() {

    
    std::vector<studentas> A;
    srand(time(NULL));
    int auto_kiekis = -1;
    bool run = true;

    while(run)
    {
        std::cout << "Pasirinkimų meniu: " << std::endl;
        std::cout << "1 - Ivesti ranka; " << std::endl;
        std::cout << "2 - Generuoti tik pazymius; " << std::endl;
        std::cout << "3 - Generuoti studentu vardus, pavardes ir pazymius; " << std::endl;
        std::cout << "4 - Skaityti informacija is failo; " << std::endl;
        std::cout << "5 - Baigti darbą; " << std::endl;
        std::cout << " Pasirinkite ";
        int pasirinkimas;
        std::cin >> pasirinkimas;

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
                    
                A.push_back(s);
                }
                break;
            }
            case 4:
            {
                std::string failas;
                std::cout << "Pasirinkite faila: " <<std::endl;
                std::cout << "kursiokai.txt , studentai10000.txt, studentai100000.txt, studentai1000000.txt" << std::endl;
                std::cin >> failas;
                auto start = std::chrono::steady_clock::now();
                skaitymas(A, failas);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<double> diff = end - start;
                double bendras = diff.count();
                rikiavimas(A);
                failoSpausdinimas(A);
                std::cout << "Failo : " << failas <<  " nuskaitymo laikas: " << bendras << "s" << std::endl;
                run = false;
                break;
            }
            
            case 5:
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
}
