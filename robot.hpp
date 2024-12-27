/**
 * @file robot.hpp
 * @brief Deklaracija klase Robot
 * @version 1.0
 * 
 * @see element.hpp
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "element.hpp"

/**
 * @brief Klasa Robot
 * 
 * Klasa Robot koja predstavlja robota u lavirintu.
 * Nasleđuje klasu Element.
 * 
 * @version 1.0
 */

class Robot : public Element {
    public:
        Robot(char simbol);
        ~Robot();
        
        char getSimbol() const;
        void setSimbol(char simbol);

        Robot* kloniraj() const override;
};

#endif // ROBOT_HPP