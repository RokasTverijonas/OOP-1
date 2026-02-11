#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

struct studentas{
    std::string vardas, pavarde;
    int* nd;
    int kiekis;
    int egzaminas;
};

double vidurkis(studentas A, int n)
{
    if(n == 0)
    {
        return 0.0;
    }
    double suma = 0;
    for(int i = 0; i < n; i++)
    {
        suma += A.nd[i];
    }
    double vidurkis = suma / n;

    return vidurkis;
}

double mediana(studentas A,int n)
{
    if(n == 0)
    {
        return 0.0;
    }
    int* temp = new int[n];
    for(int i = 0; i < n; i++)
    {
        temp[i] = A.nd[i];
    }
    std::sort(temp, temp + n);

    double rez;
    if(n % 2 != 0)
    {
        rez = temp[n / 2];
    }
    else
    {
        rez = (temp[n / 2] + temp[(n - 1) / 2]) / 2.0;
    }
    delete[] temp;
    return rez;

}

double galutinis(studentas A, double balai)
{
    double galutinis = 0.4 * balai + 0.6 * A.egzaminas;
    return galutinis;

}

int main() {

    char pasirinkimas;
    studentas* A = nullptr;
    int m = 0;

    while(true)
    {
        std:: string vardas;
        std::cout << "Iveskite " << m + 1 << " studento varda ('pabaiga' - baigia ivedinejima): " << std::endl;
        std::cin >> vardas;
        if(vardas == "pabaiga")
        {
            break;
        }

        std::string pavarde;
        std::cout << "Iveskite studento pavarde: " << std::endl;
        std::cin >> pavarde;

        studentas* temp = new studentas[m + 1];
        for(int i = 0;i < m; i++)
        {
            temp[i] = A[i];
        }
        delete[] A;
        A = temp;

        A[m].vardas = vardas;
        A[m].pavarde = pavarde;

        int* nd_laikinas = nullptr;
        int n = 0;
        
        while(true)
        {
            int nd;
            std::cout << "Iveskite " << n + 1 <<  "namu darbo ivertinima ( 0 - baigti): " << std::endl;
            std::cin >> nd;
            if(nd == 0)
            {
                break;
            }

            if(std::cin.fail() || nd < 0 || nd > 10)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ivedete neteisingai, bandykite dar karta!" << std::endl;
                continue;
            }

            int* nd_temp = new int[n + 1];
            
            for(int j = 0; j < n; j++)
            {
                nd_temp[j] = nd_laikinas[j];
            }
            delete[] nd_laikinas;
            nd_laikinas = nd_temp;

            nd_laikinas[n] = nd;
            n++;
        }

        A[m].kiekis = n;
        A[m].nd = new int[n];
        for(int i = 0; i < n; i++)
        {
            A[m].nd[i] = nd_laikinas[i];
        }
        delete[] nd_laikinas;

        std::cout << "Iveskite " << m + 1 << " studento egzamino rezultata: " << std::endl;
        std::cin >> A[m].egzaminas;

         while(true)
            {
                std::cout << "Iveskite " << m + 1 << " studento egzamino rezultata: " << std::endl;
                std::cin >> A[m].egzaminas;
                if(!std::cin.fail() && A[m].egzaminas >= 0 && A[m].egzaminas <= 10)
                {
                    break;
                }
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ivedete neteisingai, bandykite dar karta!" << std::endl;
            }

        m++;
    }

    while(true)
    {
        std::cout << "Skaiciuoti pagal vidurki (v) ar mediana (m)? " << std::endl;
        std::cin >> pasirinkimas;
        pasirinkimas = tolower(pasirinkimas);
        if(pasirinkimas == 'v' || pasirinkimas == 'm')
        {
            break;
        }
        std::cout << "Ivedete neteisingai, iveskite (v) arba (m)" << std::endl;
    }

    std::cout << std::left << std::setw(10) << "Vardas" << std::setw(10) << "Pavarde";
    
    if(pasirinkimas == 'm')
    {
        std::cout << std::setw(20) << "Galutinis (Med.)" << std::endl;
    }
    else
    {
        std::cout << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    }
    
    std::cout << "------------------------------------------" << std::endl;

    for(int i = 0; i < m; i++)
    {
        double nd_rez;
        if(pasirinkimas == 'm')
        {
            nd_rez = mediana(A[i], A[i].kiekis);
        }
        else
        {
            nd_rez = vidurkis(A[i], A[i].kiekis);
        }
        double galutinis_rez = galutinis(A[i], nd_rez);
        std::cout <<std::setw(10) <<  A[i].vardas << std::setw(10) << A[i].pavarde << std::setw(20) << std::fixed << std::setprecision(2) << galutinis_rez << std::endl;
    }


    for(int i = 0; i < m; i++)
    {
        delete[] A[i].nd;
    }
    delete[] A;

}
