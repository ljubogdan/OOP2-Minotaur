#include "minotaur.hpp"

Minotaur::Minotaur(int x, int y, char simbol) : Element(x, y, simbol) {
}

Minotaur::~Minotaur() {
}

void Minotaur::pomeriNa(int x, int y) {
    setX(x);
    setY(y);
}

