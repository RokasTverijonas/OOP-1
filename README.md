# Projekto aprašymas
Programa skirta studentų akademinių pasiekimų informacijos apdorojimui. Vartotojas gali rinktis, ar studentų informaciją įveda jis pats, ar informacija yra generuojama automatiškai. Programoje leidžia generuoti, nuskaityti studentų failus bei atlikti skirtingus programos veikimo laiko testus. Programos veikimo spartos testavimui naudojami skirtingi konteineriai.

# Naudojimosi instrukcija
1. Nusiklonuokite repozitoriją:
   
   ```
   git clone https://github.com/RokasTverijonas/OOP-1.git
   ```
2. Projekto kompiliavimas su CMake
   
   ```
   cd jusu-projektas
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Paleiskite programą
   
   ```
   ./programa1
   ```

Kompiuterio specifikacijos:

|       CPU      |  RAM |    SSD     | 
|----------------|------|------------| 
| Intel i5-8265U | 16GB | NVMe 256GB |      
--------------------------------------

# Tyrimo rezultatai:

# Vector

| Studentų skaičius | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras   |
| ----------------- | ---------   | -----------| ----------  |---------  |
| 1 000             | 0.012991 s  |0.00122235 s|0.000392021 s|0.0146054 s|
| 10 000            | 0.037484 s  |0.0117717 s |0.00272762 s |0.0519833 s|
| 100 000           | 0.314213 s  |0.151042 s  |0.0313843 s  |0.496639 s |
| 1 000 000         | 3.07692 s   |1.9735 s    |0.362729 s   |5.41315 s  |
| 10 000 000        | 32.7719 s   |25.0583 s   |4.2079 s     |62.0381 s  |
--------------------------------------------------------------------------

# List

| Studentų skaičius | Nuskaitymas |  Rikiavimas | Skirstymas  |  Bendras   |
| ----------------- | ---------   | ------------| ----------  |------------|
| 1 000             | 0.0085202 s |0.000505202 s|0.000384218 s|0.00940962 s|
| 10 000            | 0.0377167 s |0.00483843 s |0.00267851 s |0.0452336 s |
| 100 000           | 0.311433 s  |0.0660897 s  |0.0399148 s  |0.417438 s  |
| 1 000 000         | 3.23784 s   |1.04269 s    |0.396396 s   |4.67692 s   |
| 10 000 000        | 33.2608 s   |15.908 s     |5.22437 s    |54.3932 s   |
----------------------------------------------------------------------------

# Deque

| Studentų skaičius | Nuskaitymas |  Rikiavimas | Skirstymas  |  Bendras   |
| ----------------- | ---------   | ------------| ----------  |------------|
| 1 000             | 0.00702668 s|0.00137994 s |0.000243451 s|0.00865007 s|
| 10 000            | 0.0341118 s |0.0143093 s  |0.00216392 s |0.050585 s  |
| 100 000           | 0.305544 s  |0.184988 s   |0.0282838 s  |0.518816 s  |
| 1 000 000         | 3.14011 s   |2.56424 s    |0.330254 s   |6.03461 s   |
| 10 000 000        | 33.3737 s   |31.4609 s    |4.05572 s    |68.8904 s   |
----------------------------------------------------------------------------



