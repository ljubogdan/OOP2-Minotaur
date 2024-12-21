#include "lavirint.hpp"

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



