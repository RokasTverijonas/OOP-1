#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

struct studentas{
    std::string vardas, pavarde;
    int* nd;
    int egzaminas;
};

double vidurkis(studentas A, int n)
{
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

int main() {

    int skaicius;
    int nd_kiekis;

    std::cout << "Iveskite studentu skaiciu: " << std::endl;
    std::cin >> skaicius;

    std::cout << "Iveskite namu darbu kieki: " << std::endl;
    std::cin >> nd_kiekis;

    char pasirinkimas;

    std::cout << "Skaiciuoti galutini bala pagal namu darbu vidurki (v) ar mediana (m)? ";
    std::cin >> pasirinkimas;
    while(pasirinkimas != 'v' && pasirinkimas != 'm')
    {
        std::cout << "Ivedete neteisingai, iveskite (v) arba (m): ";
        std::cin >> pasirinkimas;
    }

    studentas* A = new studentas[skaicius];


    for(int i = 0; i < skaicius; i++)
    {
        std::cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
        std::cin >> A[i].vardas >> A[i].pavarde;
        
        std::cout << "Iveskite " << i + 1 << " studento namu darbu ivertinimus" << std::endl;
        A[i].nd = new int[nd_kiekis];
        for(int j = 0; j < nd_kiekis; j++)
        {
            std::cout << "Iveskite " << j + 1 << " ivertinima:"<< std::endl;
            std::cin >> A[i].nd[j];
        }

        std::cout << "Iveskite " << i + 1 << " studento egzamino rezultata" << std::endl;
        std::cin >> A[i].egzaminas;

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

    for(int i = 0; i < skaicius; i++)
    {
        double nd_rez;
        if(pasirinkimas == 'm')
        {
            nd_rez = mediana(A[i], nd_kiekis);
        }
        else
        {
            nd_rez = vidurkis(A[i], nd_kiekis);
        }
        double galutinis = 0.4 * nd_rez + 0.6 * A[i].egzaminas;
        std::cout <<std::setw(10) <<  A[i].vardas << std::setw(10) << A[i].pavarde << std::setw(20) << std::fixed << std::setprecision(2) << galutinis << std::endl;
    }


    for(int i = 0; i < skaicius; i++)
    {
        delete[] A[i].nd;
    }
    delete[] A;

}
