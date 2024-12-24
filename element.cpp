#include "element.hpp"

Element::Element(char simbol) {
    this->simbol = simbol;
}

Element::~Element() {
}

char Element::getSimbol() const {
    return simbol;
}

void Element::setSimbol(char simbol) {
    this->simbol = simbol;
}

Element* Element::kloniraj() const {
    return new Element(*this);
}

