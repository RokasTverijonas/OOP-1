#include <iostream>
#include <string>

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

int main() {

    int skaicius;
    int nd_kiekis;

    std::cout << "Iveskite studentu skaiciu: " << std::endl;
    std::cin >> skaicius;

    std::cout << "Iveskite namu darbu kieki: " << std::endl;
    std::cin >> nd_kiekis;

    studentas* A = new studentas[skaicius];


    for(int i = 0; i < skaicius; i++)
    {
        std::cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
        std::cin >> A[i].vardas >> A[i].pavarde;
        
        std::cout << "Iveskite " << i + 1 << " studento namu darbu ivertinimus";
        A[i].nd = new int[nd_kiekis];
        for(int j = 0; j < nd_kiekis; j++)
        {
            std::cin >> A[i].nd[j];
            std::cout << "Iveskite dar: " << std::endl;
        }

        std::cout << "Iveskite " << i + 1 << " studento egzamino rezultata" << std::endl;
        std::cin >> A[i].egzaminas;

    }


    for(int i = 0; i < skaicius; i++)
    {
        delete[] A[i].nd;
    }
    delete[] A;

}
