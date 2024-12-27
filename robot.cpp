/**
 * @file robot.cpp
 * @brief Implementacija metoda klase Robot
 * @version 1.0
 * 
 * Implementacija svih metoda klase Robot.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see robot.hpp
 */

#include "robot.hpp"

/**
 * @brief Konstruktor klase Robot
 * 
 * Konstruktor klase Robot koji prima simbol elementa.
 * 
 * @param simbol simbol elementa
 * 
 * Postavlja vrednost atributa simbol.
 * 
 * @return
 * 
 * @example Robot robot('R');
 */

Robot::Robot(char simbol) : Element(simbol) {
}

/**
 * @brief Destruktor klase Robot
 * 
 * @return
 * 
 * @example Robot::~Robot();
 */

Robot::~Robot() {
}

/**
 * @brief Metoda getSimbol
 * 
 * Metoda koja vraća vrednost atributa simbol.
 * 
 * @return char
 * 
 * @example char simbol = robot.getSimbol();
 */

char Robot::getSimbol() const {
    return Element::getSimbol();
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
 * @example robot.setSimbol('R');
 */

void Robot::setSimbol(char simbol) {
    Element::setSimbol(simbol);
}

/**
 * @brief Metoda kloniraj
 * 
 * Metoda koja kreira novi objekat klase Robot.
 * Ova metoda je implementirana zbog nasleđivanja klase Element.
 * Override-uje se metoda kloniraj iz klase Element.
 * 
 * @return Robot*
 * 
 * @example Robot* robot = new Robot('R');
 */

Robot* Robot::kloniraj() const {
    return new Robot(*this);
}