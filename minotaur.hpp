/**
 * @file minotaur.hpp
 * @brief Deklaracija klase Minotaur
 * @version 1.0
 * 
 * Deklaracija klase Minotaur koja predstavlja Minotaura u lavirintu.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see element.hpp
 */

#ifndef MINOTAUR_HPP
#define MINOTAUR_HPP

#include "element.hpp"

/**
 * @brief Klasa Minotaur
 * 
 * Klasa Minotaur koja predstavlja Minotaura u lavirintu.
 * Nasleđuje klasu Element.
 * Za sad nema specifičnih atributa ili metoda.
 * 
 * @version 1.0
 */

class Minotaur : public Element {
    public:
        Minotaur(char simbol);
        ~Minotaur();

        Minotaur* kloniraj() const override;
};

#endif // MINOTAUR_HPP
