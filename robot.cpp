#include "robot.hpp"

Robot::Robot(int x, int y, char simbol) : Element(x, y, simbol) {
}

Robot::~Robot() {
}

void Robot::pomeriNa(int x, int y) {
    setX(x);
    setY(y);
}