/**
 * @file upis_stanja.hpp
 * @brief Deklaracija klase UpisStanja
 * @version 1.0
 * 
 * @see lavirint.hpp
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see upis_stanja.cpp
 */
#ifndef UPIS_STANJA_HPP
#define UPIS_STANJA_HPP

#include <fstream>
#include "lavirint.hpp"

/**
 * @brief Klasa UpisStanja
 * 
 * Klasa UpisStanja koja omogućava upisivanje stanja igre u fajl.
 * U fajl upisujemo matricu lavirinta i ishod igre.
 * 
 * @version 1.0
 */

class UpisStanja {
    public:
        static void upisiUFajl(Lavirint& lavirint, int stanje);
};

#endif // UPIS_MATRICE_HPP