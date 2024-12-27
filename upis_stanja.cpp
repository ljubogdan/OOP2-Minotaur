/**
 * @file upis_stanja.cpp
 * @brief Implementacija metoda klase UpisStanja
 * @version 1.0
 * 
 * Implementacija metoda klase UpisStanja.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see upis_stanja.hpp
 * @see lavirint.hpp
 */

#include "upis_stanja.hpp"

/**
 * @brief Metoda upisiUFajl
 * 
 * Metoda koja upisuje stanje igre u fajl.
 * Upisujemo matricu lavirinta i ishod igre.
 * Kreiramo ofstream objekat i otvaramo fajl "lavirint.txt".
 * 
 * @param lavirint referenca na objekat klase Lavirint
 * @param stanje indikator stanja igre
 * 
 * @return
 * 
 * @example UpisStanja::upisiUFajl(*lavirint, procenaStanja());
 */

void UpisStanja::upisiUFajl(Lavirint& lavirint, int stanje) {
    std::ofstream izlazniFajl("lavirint.txt");
    if (stanje == 1) {
        izlazniFajl << "Robot je pobedio!" << std::endl;
    } else if (stanje == 2) {
        izlazniFajl << "Minotaur je pobedio!" << std::endl;
    } else if (stanje == 3) {
        izlazniFajl << "Igra je prekinuta (Q)!" << std::endl;
    }

    izlazniFajl << std::endl;

    Element*** matrica = lavirint.getMatrica();
    for (int i = 0; i < lavirint.getBrojRedova(); i++) {
        for (int j = 0; j < lavirint.getBrojKolona(); j++) {
            izlazniFajl << matrica[i][j]->getSimbol();
        }
        izlazniFajl << std::endl;
    }

    izlazniFajl.close();
}