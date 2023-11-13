#include "init.h"
#include "robot.h"

// check whether the robot can go each direction
// the block on that direction should not contain any block，is a wall or been walked
bool canGoEast(){
    return !(robot.onSquare->right->containBlock
        ||robot.onSquare->right->isWall
        ||robot.onSquare->right->isWalked);
}

bool canGoWest(){
    return !(robot.onSquare->left->containBlock
        ||robot.onSquare->left->isWall
        ||robot.onSquare->left->isWalked);
}

bool canGoSouth(){
    return !(robot.onSquare->down->containBlock
        ||robot.onSquare->down->isWall
        ||robot.onSquare->down->isWalked);
}

bool canGoNorth(){
    return !(robot.onSquare->up->containBlock
        ||robot.onSquare->up->isWall
        ||robot.onSquare->up->isWalked);
}

void goNorth(){
    faceNorth();
    forward();
}

void goSouth(){
    faceSouth();
    forward();
}

void goEast(){
    faceEast();
    forward();
}

void goWest(){
    faceWest();
    forward();
}

void deepSearch(){
    // found the marker and return home
    if (atMarker()){
        pickUpMarker();
        return;
    } else {  
        // check all directions
        if(canGoEast()){
            goEast();
            robot.onSquare -> isWalked = true;
            deepSearch();
            // move on to the previous block
            goWest();
            if(isCarryingMarker()){
                return;
            }
        }

        if(canGoWest()){
            goWest();
            robot.onSquare -> isWalked = true;
            deepSearch();
            goEast();
            if(isCarryingMarker()){
                return;
            }
        }

        if(canGoSouth()){
            goSouth();
            robot.onSquare -> isWalked = true;
            deepSearch();
            goNorth();
            if(isCarryingMarker()){
                return;
            }
        }

        if(canGoNorth()){
            goNorth();
            robot.onSquare -> isWalked = true;
            deepSearch();
            goSouth();
            if(isCarryingMarker()){
                return;
            }
        }
        // checked all directions, return previous one
        return;
    }
}

void runRobot(){
    for (int i = MARKER_COUNT; i > 0; i --){
        // find the marker and take back
        deepSearch();
        dropMarker();
        // clear the previous path record
        for(int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                allSquares[i][j].isWalked = false;
            }
        }
    }
}