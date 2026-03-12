#include "skaiciavimai.h"
#include <algorithm>


double vidurkis(const studentas& A)
{
    if(A.nd.empty())
    {
        return 0.0;
    }

    double suma = 0;

    for(int x : A.nd)
    {
        suma += x;
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

    if(n % 2 == 0)
    {
        return (temp[n / 2] + temp[(n - 1) / 2]) / 2.0;
    }
    else
    {
        return temp[n/2];
    }

}

double galutinis(const studentas& A, double balai)
{
    return 0.4 * balai + 0.6 * A.egzaminas;
}
