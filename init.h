#ifndef INIT_H
#define INIT_H
#include <stdlib.h>
#include"struct.h"
#include"constants.h"

// Squares
Square allSquares[10][10] = {};
// Walls
Square walls = {};

// Robot
Robot robot;
void initRobot(){
    robot.x = home_X;
    robot.y = home_Y; 
    robot.isCarryMarker = false; 
    robot.onSquare = &allSquares[robot.x][robot.y];
    strcpy(robot.direction,INIT_DIRECTION);
}

// Markers
Marker marker[MARKER_COUNT];
void initMarker(){
    for (int i = 0; i < MARKER_COUNT; i++){
        marker[i].x = MARKERS_X[i];
        marker[i].y = MARKERS_Y[i];
        marker[i].isPicked = false;
    }
}

// store marker information into squares
void storeMarker(){
    for (int i = 0; i < MARKER_COUNT; i++){
        allSquares[marker[i].x][marker[i].y].containMarker = true;
        allSquares[marker[i].x][marker[i].y].hasMarker = &marker[i];
    }
}

// store block information into squares
void storeBlocks(){
    for (int i = 0; i < BLOCK_COUNT; i++){
        allSquares[BLOCK_X[i]][BLOCK_Y[i]].containBlock = true;
    }
}

void storeWalls(int posX, int posY){
    //let the adjecent square to be wall if near a wall
    if (posX == 0){
        allSquares[posX][posY].left = &walls;
    } if (posX == 9) {
        allSquares[posX][posY].right = &walls;
    } if (posY == 0) {
        allSquares[posX][posY].up = &walls;
    } if (posY == 9) {
        allSquares[posX][posY].down = &walls;
    }
}

void createSquares(){
    for (int posX = 0; posX < 10; posX ++){
        for (int posY =0; posY < 10; posY ++){
            // init information
            allSquares[posX][posY].containMarker = false;
            allSquares[posX][posY].containBlock = false;
            allSquares[posX][posY].isHome = false;
            allSquares[posX][posY].isWall = false;

            // The operation %10 here is to prevent the position out of the range (10x10)
            allSquares[posX][posY].left = &allSquares[(posX-1)%10][posY];
            allSquares[posX][posY].right = &allSquares[(posX+1)%10][posY];
            allSquares[posX][posY].up = &allSquares[posX][(posY-1)%10];
            allSquares[posX][posY].down = &allSquares[posX][(posY+1)%10];

            storeWalls(posX, posY);
        }        
    }
}

void inputHomeAddress(int argc, char **argv){
    if (argc == 4){
        char *pInitDirection = initDirection;
        home_X = atoi(argv[1]);
        home_Y = atoi(argv[2]);
        pInitDirection = argv[3];
    }
}

// create all squares as objects containning the information about marker/block/home
// and pointers to the squares next to them
void initSquares (){
    // init the wall
    walls.isWall = true;

    createSquares();
    
    storeMarker();
    storeBlocks();
    
    // store home 
    allSquares[home_X][home_Y].isHome = true;
}

void init(int argc, char **argv){
    inputHomeAddress(argc, argv);
    initRobot();
    initMarker();
    initSquares();
}

#endif

