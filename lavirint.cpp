#include "lavirint.hpp"
#include "lavirint_utils.hpp"

Lavirint::Lavirint(int brojRedova, int brojKolona) {
    this->brojRedova = brojRedova;
    this->brojKolona = brojKolona;

    matrica = new Element*[brojRedova];
    for (int i = 0; i < brojRedova; i++) {
        matrica[i] = new Element[brojKolona];
    }
}

Lavirint::~Lavirint() {
    for (int i = 0; i < brojRedova; i++) {
        delete[] matrica[i];
    }
    delete[] matrica;
}

int Lavirint::getBrojRedova() const {
    return brojRedova;
}

int Lavirint::getBrojKolona() const {
    return brojKolona;
}

void Lavirint::setBrojRedova(int brojRedova) {
    this->brojRedova = brojRedova;
}

void Lavirint::setBrojKolona(int brojKolona) {
    this->brojKolona = brojKolona;
}

Element& Lavirint::getElement(int x, int y) const {
    return matrica[x][y];
}

void Lavirint::setElement(int x, int y, Element& element) {
    matrica[x][y] = element;
}

void Lavirint::generisiLavirint() {
    LavirintUtils::generisiLavirint(*this, 5);
}






