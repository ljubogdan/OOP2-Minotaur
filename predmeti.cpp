/**
 * @file predmeti.cpp
 * @brief Implementacija metoda klase Predmet
 * @version 1.0
 * 
 * Implementacija svih metoda klase Predmet.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see predmeti.hpp
 */

#include "predmeti.hpp"

/**
 * @brief Konstruktor klase Predmet
 * 
 * Konstruktor klase Predmet koji prima simbol elementa i efekat.
 * 
 * @param simbol simbol elementa
 * @param efekat efekat predmeta
 * 
 * Postavlja vrednosti atributa simbol i efekat.
 * 
 * @return
 * 
 * @example Predmet predmet('P', "Magla rata");
 */

Predmet::Predmet(char simbol, std::string efekat) : Element(simbol), efekat(efekat) {
}

/**
 * @brief Destruktor klase Predmet
 * 
 * @return
 * 
 * @example Predmet::~Predmet();
 */

Predmet::~Predmet() {
}

/**
 * @brief Metoda getEfekat
 * 
 * Metoda koja vraća vrednost atributa efekat.
 * 
 * @return std::string
 * 
 * @example std::string efekat = predmet.getEfekat();
 */

std::string Predmet::getEfekat() const {
    return efekat;
}

/**
 * @brief Metoda setEfekat
 * 
 * Metoda koja postavlja vrednost atributa efekat.
 * 
 * @param efekat efekat predmeta
 * 
 * @return
 * 
 * @example predmet.setEfekat("Magla rata");
 */

void Predmet::setEfekat(std::string efekat) {
    this->efekat = efekat;
}
