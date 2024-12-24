#include "minotaur.hpp"

Minotaur::Minotaur(char simbol) : Element(simbol) {
}

Minotaur::~Minotaur() {
}

Minotaur* Minotaur::kloniraj() const {
    return new Minotaur(*this);
}


