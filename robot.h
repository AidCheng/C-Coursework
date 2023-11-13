#ifndef ROBOT_H
#define ROBOT_H

#include "robot.c"

// robot operations
void forward();
void left();
void right();
void faceNorth();
void faceSouth();
void faceEast();
void faceNorth();
void turnAround();

// environment detection
bool canMoveForward();
bool atMarker();
bool atHome();
bool isCarryingMarker();

// marker interaction
void pickUpMarker();
void dropMarker();

#endif
