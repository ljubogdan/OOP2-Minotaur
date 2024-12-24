#include "predmeti.hpp"

Predmet::Predmet(int x, int y, char simbol, std::string efekat) : Element(x, y, simbol), efekat(efekat) {
}

Predmet::~Predmet() {
}

std::string Predmet::getEfekat() const {
    return efekat;
}

void Predmet::setEfekat(std::string efekat) {
    this->efekat = efekat;
}
