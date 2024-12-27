/**
 * @file minotaur.cpp
 * @brief Implementacija metoda klase Minotaur
 * @version 1.0
 * 
 * Implementacija svih metoda klase Minotaur.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see minotaur.hpp
 */

#include "minotaur.hpp"

/**
 * @brief Konstruktor klase Minotaur
 * 
 * Konstruktor klase Minotaur koji prima simbol elementa.
 * 
 * @param simbol simbol elementa
 * 
 * Postavlja vrednost atributa simbol.
 * 
 * @return
 * 
 * @example Minotaur minotaur('#');
 */

Minotaur::Minotaur(char simbol) : Element(simbol) {
}

/**
 * @brief Destruktor klase Minotaur
 * 
 * @return
 * 
 * @example Minotaur::~Minotaur();
 */

Minotaur::~Minotaur() {
}

/**
 * @brief Metoda kloniraj
 * 
 * Metoda koja kreira novi objekat klase Minotaur.
 * Ova metoda je implementirana zbog nasleđivanja klase Element.
 * Override-uje se metoda kloniraj iz klase Element.
 * 
 * @return Minotaur*
 * 
 * @example Minotaur* minotaur = new Minotaur('#');
 */

Minotaur* Minotaur::kloniraj() const {
    return new Minotaur(*this);
}


