/**
 * @file element.hpp
 * @brief Deklaracija klase Element
 * @version 1.0
 * 
 * Deklaracija klase Element koja predstavlja osnovni element lavirinta.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 */

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

/**
 * @brief Klasa Element
 * 
 * Klasa Element koja predstavlja osnovni element lavirinta.
 * Svaki objekat u laviritu je ili Element ili naslednik klase Element.
 * 
 * @param simbol simbol elementa
 * 
 * @version 1.0
 */
class Element {
    protected:
        char simbol;
    public:
        Element(char simbol);
        Element() = default;
        virtual ~Element();
        char getSimbol() const;
        void setSimbol(char simbol);

        virtual Element* kloniraj() const;
};

#endif // ELEMENT_HPP