#include "element.hpp"

Element::Element(int x, int y, char simbol) {
    this->x = x;
    this->y = y;
    this->simbol = simbol;
}

Element::~Element() {
}

int Element::getX() const {
    return x;
}

int Element::getY() const {
    return y;
}

char Element::getSimbol() const {
    return simbol;
}

void Element::setX(int x) {
    this->x = x;
}

void Element::setY(int y) {
    this->y = y;
}

void Element::setSimbol(char simbol) {
    this->simbol = simbol;
}


