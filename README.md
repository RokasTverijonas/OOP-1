# Projekto aprašymas
Programa skirta studentų akademinių pasiekimų informacijos apdorojimui. Vartotojas gali rinktis, ar studentų informaciją įveda jis pats, ar informacija yra generuojama automatiškai. Programoje leidžia generuoti, nuskaityti studentų failus bei atlikti skirtingus programos veikimo laiko testus. Programos veikimo spartos testavimui naudojami skirtingi konteineriai.

# Naudojimosi instrukcija
1. Nusiklonuokite repozitoriją:
   
   ```
   git clone https://github.com/RokasTverijonas/OOP-1.git
   ```

2. Įsidiekite CMake (Linux(Ubuntu/Debian))

   ```
   sudo apt update
   sudo apt install cmake
   ```

3. Projekto kompiliavimas su CMake
   
   ```
   cd OOP-1
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Paleiskite programą
   
   ```
   ./programa1
   ```

# Kompiuterio specifikacijos:

|       CPU      |  RAM |    SSD     | 
|----------------|------|------------| 
| Intel i5-8265U | 16GB | NVMe 256GB |      
--------------------------------------

# Tyrimo rezultatai:

- Šiame tyrime analizuojamas skirtingų konteinerių (vector, list, deque) efektyvumas apdorojant studentų duomenis.
- Eksperimentuose naudojami skirtingo dydžio failai (nuo 1000 iki 10000000 studentų įrašų)
- Pirmoje strategijoje studentai yra padalinami į du naujus konteinerius
- antroje strategijoje iš bendro studentų koneteinerio į naują konteinerį yra perkeliami tik nepažangūs studentai ir jie tuo pčaiu yra ištrinami iš pagrindinio konteinerio. Tai sutaupo atminties.
- Trečioje strategijoje, taip pat, iš bendro studentų koneteinerio į naują konteinerį yra perkeliami tik nepažangūs studentai ir jie tuo pačiu yra ištrinami iš pagrindinio konteinerio, bet šiuo atveju yra naudojami efektyvūs algoritmai

# 1 Strategiija

1000 studentų

|   Konteineris   | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras    |
| ----------------| ----------- | -----------| ----------- |----------- |
|     vector      | 0.00817195 s|0.00119888 s|0.00037852 s |0.00974935 s|
|     list        | 0.0188767 s |0.00187046 s|0.00152634 s |0.0222735 s |
|     deque       |0.00800918 s |0.00133549 s|0.000255851 s|0.00960053 s|
-------------------------------------------------------------------------

10000 studentų

|   Konteineris   | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras    |
| ----------------| ----------- | -----------| ----------- |----------- |
|     vector      | 0.0354387 s |0.0125416 s |0.00305164 s |0.051032 s  |
|     list        | 0.0496955 s |0.00520858 s|0.00379677 s |0.0587008 s |
|     deque       |0.0335764 s  |0.0148457 s |0.00211513 s |0.0505372 s |
-------------------------------------------------------------------------

100000 studentų

|   Konteineris   | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras    |
| ----------------| ----------- | -----------| ----------- |----------- |
|     vector      | 0.315538 s  |0.159351 s  |0.0425798 s  |0.517469 s  |
|     list        | 0.32925 s   |0.0732792 s |0.0428928 s  |0.445422 s  |
|     deque       | 0.30624 s   |0.188056 s  |0.0270567 s  |0.521352 s  |
-------------------------------------------------------------------------

1000000 studentų

|   Konteineris   | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras    |
| ----------------| ----------- | -----------| ----------- |----------- |
|     vector      | 3.06587 s   |2.04424 s   |0.361464 s   |5.47158 s   |
|     list        | 3.16713 s   |1.12318 s   |0.42037 s    |4.71069 s   |
|     deque       | 3.01865 s   |2.39508 s   |0.282664 s   |5.69639 s   |
-------------------------------------------------------------------------

10000000 studentų

|   Konteineris   | Nuskaitymas | Rikiavimas | Skirstymas  | Bendras    |
| ----------------| ----------- | -----------| ----------- |----------- |
|     vector      |33.221 s     |25.6777 s   |4.19487 s    |63.0936 s   |
|     list        |32.211 s     |16.1624 s   |5.36192 s    |53.7354 s   |
|     deque       |34.0622 s    |31.4753 s   |4.03432 s    |69.5718 s   |
-------------------------------------------------------------------------

# 2 Strategija

1000 studentų

| Konteineris | Nuskaitymas  | Rikiavimas   | Skirstymas    | Bendras     |
| ----------- | ------------ | ------------ | ------------- | ----------- |
| vector      | 0.0138443 s  | 0.00402271 s | 0.000896802 s | 0.0187638 s |
| list        | 0.0112991 s  | 0.00101852 s | 0.000723947 s | 0.0130416 s |
| deque       | 0.00831709 s | 0.00157084 s | 0.000265976 s | 0.0101539 s |
---------------------------------------------------------------------------

10000 studentų

| Konteineris | Nuskaitymas | Rikiavimas   | Skirstymas   | Bendras     |
| ----------- | ----------- | ------------ | ------------ | ----------- |
| vector      | 0.0488885 s | 0.0119982 s  | 0.003567 s   | 0.0644537 s |
| list        | 0.0468325 s | 0.00653412 s | 0.003164 s   | 0.0565306 s |
| deque       | 0.035005 s  | 0.0152959 s  | 0.00237919 s | 0.0526801 s |
-------------------------------------------------------------------------

100000 studentų

| Konteineris | Nuskaitymas | Rikiavimas  | Skirstymas  | Bendras    |
| ----------- | ----------- | ----------- | ----------- | ---------- |
| vector      | 0.309307 s  | 0.152284 s  | 0.0251493 s | 0.48674 s  |
| list        | 0.32738 s   | 0.0731535 s | 0.0429417 s | 0.443475 s |
| deque       | 0.30704 s   | 0.179855 s  | 0.0241984 s | 0.511093 s |
----------------------------------------------------------------------

1000000 studentų 

| Konteineris | Nuskaitymas | Rikiavimas | Skirstymas | Bendras   |
| ----------- | ----------- | ---------- | ---------- | --------- |
| vector      | 3.10032 s   | 2.00739 s  | 0.260461 s | 5.36817 s |
| list        | 3.52226 s   | 1.24222 s  | 0.472218 s | 5.2367 s  |
| deque       | 3.03269 s   | 2.31626 s  | 0.264776 s | 5.61373 s |
-------------------------------------------------------------------
10000000 studentų

| Konteineris | Nuskaitymas | Rikiavimas | Skirstymas | Bendras   |
| ----------- | ----------- | ---------- | ---------- | --------- |
| vector      | 35.327 s    | 25.2403 s  | 3.35782 s  | 63.9251 s |
| list        | 32.9469 s   | 16.5527 s  | 5.77559 s  | 55.2752 s |
| deque       | 32.5057 s   | 31.1508 s  | 4.0153 s   | 67.6718 s |
-------------------------------------------------------------------

# 3 strategija

1000 studentų

| Konteineris | Nuskaitymas  | Rikiavimas   | Skirstymas    | Bendras      |
| ----------- | ------------ | ------------ | ------------- | ------------ |
| vector      | 0.0165731 s  | 0.00479763 s | 0.000950303 s | 0.022321 s   |
| list        | 0.00738397 s | 0.00049343 s | 0.000373542 s | 0.00825094 s |
| deque       | 0.0112991 s  | 0.00361972 s | 0.000691157 s | 0.01561 s    |
----------------------------------------------------------------------------

10000 studentų

| Konteineris | Nuskaitymas | Rikiavimas   | Skirstymas   | Bendras     |
| ----------- | ----------- | ------------ | ------------ | ----------- |
| vector      | 0.0498351 s | 0.0126791 s  | 0.00231462 s | 0.0648289 s |
| list        | 0.0345341 s | 0.00465886 s | 0.00315724 s | 0.0423502 s |
| deque       | 0.0440645 s | 0.0156011 s  | 0.00255744 s | 0.062223 s  |
-------------------------------------------------------------------------

100000 studentų

| Konteineris | Nuskaitymas | Rikiavimas  | Skirstymas  | Bendras    |
| ----------- | ----------- | ----------- | ----------- | ---------- |
| vector      | 0.330439 s  | 0.165557 s  | 0.0283918 s | 0.524389 s |
| list        | 0.311239 s  | 0.0662796 s | 0.0465816 s | 0.4241 s   |
| deque       | 0.321499 s  | 0.197386 s  | 0.0298678 s | 0.548753 s |
----------------------------------------------------------------------

1000000 studentų

| Konteineris | Nuskaitymas | Rikiavimas | Skirstymas | Bendras   |
| ----------- | ----------- | ---------- | ---------- | --------- |
| vector      | 3.57726 s   | 2.25742 s  | 0.28823 s  | 6.12291 s |
| list        | 3.29839 s   | 1.0991 s   | 0.514405 s | 4.9119 s  |
| deque       | 3.29092 s   | 2.88852 s  | 0.34888 s  | 6.52832 s |
-------------------------------------------------------------------

10000000 studentų

| Konteineris | Nuskaitymas | Rikiavimas | Skirstymas | Bendras   |
| ----------- | ----------- | ---------- | ---------- | --------- |
| vector      | 36.5714 s   | 26.6433 s  | 3.78865 s  | 67.0034 s |
| list        | 35.623 s    | 17.7846 s  | 6.64203 s  | 60.0496 s |
| deque       | 34.5543 s   | 32.2247 s  | 4.28649 s  | 71.0655 s |
-------------------------------------------------------------------