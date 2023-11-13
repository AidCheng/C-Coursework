#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "init.h"
#include "constants.h"
#include "struct.h"
#include "draw.h"
#include "robot.h"
#include "navigation.h"

int main(int argc, char  **argv){
    // initialise the squares and markers and objects
    init(argc, argv);
    drawBackground(); 
    drawObjects();
    runRobot();
}

