#include "robot.hpp"

Robot::Robot(int x, int y, char simbol) : Element(x, y, simbol) {
}

Robot::~Robot() {
}

int Robot::getX() const {
    return Element::getX();
}

int Robot::getY() const {
    return Element::getY();
}

char Robot::getSimbol() const {
    return Element::getSimbol();
}

void Robot::setX(int x) {
    Element::setX(x);
}

void Robot::setY(int y) {
    Element::setY(y);
}

void Robot::setSimbol(char simbol) {
    Element::setSimbol(simbol);
}

void Robot::pomeriNa(int x, int y) {
    setX(x);
    setY(y);
}