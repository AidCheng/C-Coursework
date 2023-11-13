#include <stdbool.h>
#include <string.h>
#include "init.h"
#include "struct.h"
#include "draw.h"

// basic functionality of the robot

bool canMoveForward(){
    // find if the block next to the given direction is a wall or block, if yes, return false
    if (strcmp(robot.direction,"up") == 0){
        return !(robot.onSquare->up->isWall||robot.onSquare->up->containBlock);
    } if (strcmp(robot.direction,"down") == 0){
        return !(robot.onSquare->down->isWall||robot.onSquare->down->containBlock);
    } if (strcmp(robot.direction,"left") == 0){
        return !(robot.onSquare->left -> isWall||robot.onSquare->left->containBlock);
    } else {
        return !(robot.onSquare->right->isWall||robot.onSquare->right->containBlock);
    }
}

void forward(){
    // change the location info of robot accoring to its direction
    if (canMoveForward()){
        if (strcmp(robot.direction,"up") == 0){
            robot.y --;
        } if (strcmp(robot.direction,"down") == 0){
            robot.y ++;
        } if (strcmp(robot.direction,"left") == 0){
            robot.x --;
        } if (strcmp(robot.direction,"right") == 0){
            robot.x ++;
        }
    }
    // update which square the robot is currently on
    robot.onSquare = &allSquares[robot.x][robot.y];
    // update and redraw the robot's position
    update();
}

void left(){
    // change the location info of robot accoring to its direction
    if (strcmp(robot.direction,"right") == 0){
        strcpy(robot.direction, "up");
    } else if (strcmp(robot.direction,"up") == 0){
        strcpy(robot.direction, "left");
    } else if (strcmp(robot.direction,"left") == 0){
        strcpy(robot.direction, "down");
    } else if (strcmp(robot.direction,"down") == 0){
        strcpy(robot.direction, "right");
    }      
    // update which square the robot is currently on
    update ();
}

void right(){
    // change the location info of robot accoring to its direction
    if (strcmp(robot.direction,"right") == 0){
        strcpy(robot.direction, "down");
    } else if (strcmp(robot.direction,"down") == 0){
        strcpy(robot.direction, "left");
    } else if (strcmp(robot.direction,"left") == 0){
        strcpy(robot.direction, "up");
    } else if (strcmp(robot.direction,"up") == 0){
        strcpy(robot.direction, "right");
    }      
    // update which square the robot is currently on
    update ();
}

void faceNorth(){
    strcpy(robot.direction, "up");
    update();
}

void faceSouth(){
    strcpy(robot.direction, "down");
    update();
}

void faceEast(){
    strcpy(robot.direction, "right");
    update();
}

void faceWest(){
    strcpy(robot.direction, "left");
    update();
}

void turnAround(){
    left();
    left();   
}

bool atMarker(){
    return robot.onSquare -> containMarker;
}

bool atHome(){
    return robot.onSquare -> isHome;
}

bool isCarryingMarker(){
    return robot.isCarryMarker;
}

void pickUpMarker(){
    if (atMarker()){
        robot.onSquare->hasMarker->isPicked = true;
        robot.onSquare->containMarker = false;
        robot.isCarryMarker = true;
        update();
    }
}

void dropMarker(){
    robot.isCarryMarker = false;
    update();
}



