#include "upis_stanja.hpp"

void UpisStanja::upisiUFajl(Lavirint& lavirint, int stanje) {
    std::ofstream izlazniFajl("lavirint.txt");
    // stanje 1 - robot pobedio, stanje 2 - minotaur pobedio, stanje 3 - prekid igre (Q)
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