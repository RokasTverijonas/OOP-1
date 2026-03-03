#include "skaiciavimai.h"
#include <algorithm>


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