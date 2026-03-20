#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <string>
#include <vector>

void skaitymas(std::vector<studentas>& A, std::string failas);
double vidurkis(const studentas& A);
double mediana(const studentas& A);
double galutinis(const studentas& A, double balai);
void rikiavimas(std::vector<studentas>& A, int kriterijus);
void spausdinimas(std::vector<studentas>& A);
void failoSpausdinimas(std::vector<studentas>& A);
void failoGeneravimas(int studKiekis);
void StudentuPadalinimas(const std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai, int kriterijus);
void atskiriFailai(std::string failas, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void tyrimasPirmas();
void tyrimasAntras(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai, int kriterijus);


#endif