#include "lavirint.hpp"
#include "lavirint_utils.hpp"

Lavirint::Lavirint(int brojRedova, int brojKolona) {
    this->brojRedova = brojRedova;
    this->brojKolona = brojKolona;

    matrica = new Element**[brojRedova];
    for (int i = 0; i < brojRedova; i++) {
        matrica[i] = new Element*[brojKolona];
        for (int j = 0; j < brojKolona; j++) {
            matrica[i][j] = new Element(i, j, ' ');
        }
    }
}

Lavirint::~Lavirint() {
    for (int i = 0; i < brojRedova; i++) {
        for (int j = 0; j < brojKolona; j++) {
            delete matrica[i][j];
        }
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
    return *matrica[x][y];
}

void Lavirint::setElement(int x, int y, const Element& element) {
    *matrica[x][y] = element;
}

Element*** Lavirint::getMatrica() const {
    return matrica;
}

void Lavirint::setMatrica(Element*** matrica) {
    this->matrica = matrica;
}

void Lavirint::generisiLavirint(int brojPredmeta) {
    LavirintUtils::generisiLavirint(*this, brojPredmeta);
}






