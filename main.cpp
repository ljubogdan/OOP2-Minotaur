/**
 * @file main.cpp
 * @brief Main program
 * @version 1.0
 * 
 * Glavni program koji pokreće igru.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 03:08:07 
 */

#include "igra.hpp"
#include <iostream>

/**
 * @brief Main funkcija
 * 
 * @param argc broj argumenata
 * @param argv argumenti
 * @return int
 * 
 * Ukoliko broj argumenata nije jednak 4, ispisuje se upotreba programa.
 * Ukoliko argumenti nisu celi brojevi, ispisuje se greška.
 * Ukoliko broj redova i kolona nije veći od 15, a broj predmeta nije veći od 3, ispisuje se greška.
 * U suprotnom, pokreće se igra.
 * Na kraju igre, ispisuje se poruka o završetku igre.
 * 
 * @example ./main_program 15 15 3
 */

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cout << RED << "Upotreba: ./main_program <broj_redova> <broj_kolona> <broj_predmeta>" << RESET << std::endl;
        return 1;
    }

    int brojRedova, brojKolona, brojPredmeta;
    try {
        brojRedova = std::stoi(argv[1]);
        brojKolona = std::stoi(argv[2]);
        brojPredmeta = std::stoi(argv[3]);
    } catch (std::exception& e) {
        std::cout << RED << "Greška: Argumenti moraju biti celi brojevi." << RESET << std::endl;
        return 1;
    }

    if (brojRedova % 2 == 0) {
        brojRedova++;
    }
    if (brojKolona % 2 == 0) {
        brojKolona++;
    }

    if (brojRedova < 15 || brojKolona < 15 || brojPredmeta < 3) {
        std::cout << RED << "Greška: Broj redova i kolona mora biti veći od 15, a broj predmeta veći od 3." << RESET << std::endl;
        return 1;
    }
    

    Igra igra(brojRedova, brojKolona, brojPredmeta);
    igra.pokreniIgru();

    igra.zavrsiIgru();
    return 0;
};