#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include "studentas.h"


void rikiavimas(std::vector<studentas>& A);
void spausdinimas(std::vector<studentas>& A);
void failoSpausdinimas(std::vector<studentas>& A);
void failoGeneravimas(int studKiekis);
void StudentuPadalinimas(const std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void atskiriFailai(std::string failas,std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);

#endif