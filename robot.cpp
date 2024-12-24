#include "robot.hpp"

Robot::Robot(char simbol) : Element(simbol) {
}

Robot::~Robot() {
}

char Robot::getSimbol() const {
    return Element::getSimbol();
}

void Robot::setSimbol(char simbol) {
    Element::setSimbol(simbol);
}

Robot* Robot::kloniraj() const {
    return new Robot(*this);
}