/**
 * @file lavirint.cpp
 * @brief Implementacija metoda klase Lavirint
 * @version 1.0
 * 
 * Implementacija svih metoda klase Lavirint.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see lavirint.hpp
 * @see lavirint_utils.hpp
 */

#include "lavirint.hpp"
#include "lavirint_utils.hpp"

/**
 * @brief Konstruktor klase Lavirint
 * 
 * Konstruktor klase Lavirint koji prima broj redova i broj kolona.
 * 
 * @param brojRedova broj redova
 * @param brojKolona broj kolona
 * 
 * Alocira memoriju za matricu elemenata.
 * 
 * @return
 * 
 * @example Lavirint lavirint(15, 15);
 * 
 * @see Lavirint::generisiLavirint
 */

Lavirint::Lavirint(int brojRedova, int brojKolona) {
    this->brojRedova = brojRedova;
    this->brojKolona = brojKolona;

    matrica = new Element**[brojRedova];
    for (int i = 0; i < brojRedova; i++) {
        matrica[i] = new Element*[brojKolona];
        for (int j = 0; j < brojKolona; j++) {
            matrica[i][j] = new Element(' ');
        }
    }
}

/**
 * @brief Destruktor klase Lavirint
 * 
 * Oslobađa resurse.
 * 
 * @return
 * 
 * @example Lavirint::~Lavirint();
 * 
 * @see Element
 */

Lavirint::~Lavirint() {
    for (int i = 0; i < brojRedova; i++) {
        for (int j = 0; j < brojKolona; j++) {
            delete matrica[i][j];
        }
        delete[] matrica[i];
    }
    delete[] matrica;
}

/**
 * @brief Metoda getBrojRedova
 * 
 * Metoda koja vraća vrednost atributa brojRedova.
 * 
 * @return int
 * 
 * @example int brojRedova = lavirint.getBrojRedova();
 */

int Lavirint::getBrojRedova() const {
    return brojRedova;
}

/**
 * @brief Metoda getBrojKolona
 * 
 * Metoda koja vraća vrednost atributa brojKolona.
 * 
 * @return int
 * 
 * @example int brojKolona = lavirint.getBrojKolona();
 */

int Lavirint::getBrojKolona() const {
    return brojKolona;
}

/**
 * @brief Metoda setBrojRedova
 * 
 * Metoda koja postavlja vrednost atributa brojRedova.
 * 
 * @param brojRedova broj redova
 * 
 * @return
 * 
 * @example lavirint.setBrojRedova(15);
 */

void Lavirint::setBrojRedova(int brojRedova) {
    this->brojRedova = brojRedova;
}

/**
 * @brief Metoda setBrojKolona
 * 
 * Metoda koja postavlja vrednost atributa brojKolona.
 * 
 * @param brojKolona broj kolona
 * 
 * @return
 * 
 * @example lavirint.setBrojKolona(15);
 */

void Lavirint::setBrojKolona(int brojKolona) {
    this->brojKolona = brojKolona;
}

/**
 * @brief Metoda getElement
 * 
 * Metoda koja vraća element na poziciji (x, y).
 * Vraća referencu na element.
 * 
 * @param x x koordinata
 * @param y y koordinata
 * 
 * @return Element&
 * 
 * @example Element& element = lavirint.getElement(0, 0);
 */

Element& Lavirint::getElement(int x, int y) const {
    return *matrica[x][y];
}

/**
 * @brief Metoda setElement
 * 
 * Metoda koja postavlja element na poziciju (x, y).
 * Prima element po referenci, dinački kreira novi element.
 * Stari element se briše.
 * 
 * @param x x koordinata
 * @param y y koordinata
 * @param element element
 * 
 * @return
 * 
 * @example lavirint.setElement(0, 0, new Element(' '));
 */

void Lavirint::setElement(int x, int y, Element* element) {
    if (matrica[x][y] != nullptr) {
        delete matrica[x][y];
    }
    matrica[x][y] = element;
}

/**
 * @brief Metoda getMatrica
 * 
 * Metoda koja vraća matricu elemenata.
 * 
 * @return Element***
 * 
 * @example Element*** matrica = lavirint.getMatrica();
 */

Element*** Lavirint::getMatrica() const {
    return matrica;
}

/**
 * @brief Metoda setMatrica
 * 
 * Metoda koja postavlja matricu elemenata.
 * 
 * @param matrica matrica elemenata
 * 
 * @return
 * 
 * @example lavirint.setMatrica(matrica);
 */

void Lavirint::setMatrica(Element*** matrica) {
    this->matrica = matrica;
}

/**
 * @brief Metoda generisiLavirint
 * 
 * Metoda koja generiše lavirint.
 * Prima broj predmeta koji treba postaviti u lavirint.
 * Koristi se funkcija generisiLavirint iz klase LavirintUtils (static).
 * 
 * @param brojPredmeta broj predmeta
 * 
 * @return
 * 
 * @example lavirint.generisiLavirint(5);
 * 
 * @see LavirintUtils::generisiLavirint
 */

void Lavirint::generisiLavirint(int brojPredmeta) {
    LavirintUtils::generisiLavirint(*this, brojPredmeta);
}






