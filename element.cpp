/**
 * @file element.cpp
 * @brief Implementacija metoda klase Element
 * @version 1.0
 * 
 * Implementacija svih metoda klase Element.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see element.hpp
 */

#include "element.hpp"

/**
 * @brief Default konstruktor klase Element
 * 
 * @return
 * 
 * @example Element element;
 */

Element::Element() {
}

/**
 * @brief Konstruktor klase Element
 * 
 * Konstruktor klase Element koji prima simbol elementa.
 * 
 * @param simbol simbol elementa
 * 
 * Postavlja vrednost atributa simbol.
 * 
 * @return
 * 
 * @example Element element('#');
 */

Element::Element(char simbol) {
    this->simbol = simbol;
}

/**
 * @brief Destruktor klase Element
 * 
 * @return
 * 
 * @example Element::~Element();
 */

Element::~Element() {
}

/**
 * @brief Metoda getSimbol
 * 
 * Metoda koja vraća vrednost atributa simbol.
 * 
 * @return char
 * 
 * @example char simbol = element.getSimbol();
 */

char Element::getSimbol() const {
    return simbol;
}

/**
 * @brief Metoda setSimbol
 * 
 * Metoda koja postavlja vrednost atributa simbol.
 * 
 * @param simbol simbol elementa
 * 
 * @return
 * 
 * @example element.setSimbol('#');
 */

void Element::setSimbol(char simbol) {
    this->simbol = simbol;
}

/**
 * @brief Metoda za kloniranje objekta
 * 
 * Metoda koja kreira novi objekat klase Element i vraća pokazivač na taj objekat.
 * Koristi se za pravljenje kopije objekta.
 * 
 * @return Element*
 * 
 * @example Element* element = element.kloniraj();
 */

Element* Element::kloniraj() const {
    return new Element(*this);
}

