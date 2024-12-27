/**
 * @file lavirint.hpp
 * @brief Deklaracija klase Lavirint
 * @version 1.0
 * 
 * @see element.hpp
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see lavirint.cpp
 * @see lavirint_utils.hpp
 * @see element.hpp
 */

#ifndef LAVIRINT_HPP
#define LAVIRINT_HPP

#include "element.hpp"
#include "predmeti.hpp"

/**
 * @brief Klasa Lavirint
 * 
 * Klasa Lavirint koja predstavlja lavirint.
 * 
 * @param brojRedova broj redova
 * @param brojKolona broj kolona
 * @param matrica matrica elemenata
 * 
 * @version 1.0
 */

class Lavirint {
    private:
        int brojRedova;
        int brojKolona;
        Element*** matrica;
    public:
        Lavirint(int brojRedova, int brojKolona);
        ~Lavirint();
        int getBrojRedova() const;
        int getBrojKolona() const;
        Element*** getMatrica() const;
        void setBrojRedova(int brojRedova);
        void setBrojKolona(int brojKolona);
        void setMatrica(Element*** matrica);

        Element& getElement(int x, int y) const;
        void setElement(int x, int y, Element* element);

        void generisiLavirint(int brojPredmeta);
};

#endif // LAVIRINT_HPP