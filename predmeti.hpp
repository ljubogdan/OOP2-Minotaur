/**
 * @file predmeti.hpp
 * @brief Deklaracija klase Predmet
 * @version 1.0
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 18:08:07
 * 
 * @see element.hpp
 */
#include "element.hpp"
#include <string>

/**
 * @brief Klasa Predmet
 * 
 * Klasa Predmet koja predstavlja predmet u lavirintu.
 * Nasleđuje klasu Element.
 * 
 * @param efekat efekat predmeta, npr. "Magla rata"
 * 
 * @version 1.0
 */

class Predmet : public Element {
    private:
        std::string efekat;
    public:
        Predmet(char simbol, std::string efekat);
        ~Predmet();

        std::string getEfekat() const;
        void setEfekat(std::string efekat);
};