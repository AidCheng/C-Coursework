#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct initData {
    int homeX;
    int homeY;
    int robotX;
    int robotY;
    char direction[6];
} initData;

typedef struct Wall {
    bool isWall;
} Wall;

// for testing, only one marker will be generated (to be modified later)
typedef struct Marker {
    // int position
    int x;
    int y;
    // whether this marker is picked
    bool isPicked;
} Marker;

typedef struct Square {
    // link to other squares
    struct Square *left;
    struct Square *right;
    struct Square *up;
    struct Square *down;
    // store the information of this square
    bool containMarker;
    bool containBlock;
    bool isWalked;
    bool isHome;
    bool isWall;
    Marker* hasMarker;
} Square;

typedef struct Robot {
    int x;
    int y;
    char direction[6];
    // boolean variable to detect whether the robot is carrying marker
    bool isCarryMarker;
    // point to the current square
    Square *onSquare;

    bool deadEnd;
} Robot;

#endif