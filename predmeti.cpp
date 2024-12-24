#include "predmeti.hpp"

Predmet::Predmet(char simbol, std::string efekat) : Element(simbol), efekat(efekat) {
}

Predmet::~Predmet() {
}

std::string Predmet::getEfekat() const {
    return efekat;
}

void Predmet::setEfekat(std::string efekat) {
    this->efekat = efekat;
}
