#include <string.h>
#include "drawapp-3.0/graphics.h"
#include "init.h"
#include "constants.h"
#include "struct.h"


void drawHome(){
    int x = home_X;
    int y = home_Y;
    // set colour to blue
    setRGBColour(108, 147, 245);

    fillRect(
        GRID_POSITION_X + x * GRID_SIZE, 
        GRID_POSITION_Y + y * GRID_SIZE, 
        GRID_SIZE, 
        GRID_SIZE);
}

void drawBlocks(){
    // set colour to grey
    setRGBColour(145, 145, 145);

    for (int i = 0; i < BLOCK_COUNT; i ++){
        fillRect(
            GRID_POSITION_X + BLOCK_X[i]*GRID_SIZE, 
            GRID_POSITION_Y + BLOCK_Y[i]*GRID_SIZE, 
            GRID_SIZE, GRID_SIZE
            );
    }
}

void drawGrid(){
    for (int x = 0; x <= MAX_SQUARES_IN_A_LINE; x++){
        // draw vertical lines
        drawLine(
            GRID_POSITION_X + x * GRID_SIZE, 
            GRID_POSITION_Y, 
            GRID_POSITION_X + x * GRID_SIZE,
            GRID_POSITION_Y + GRID_LENGTH);
    }
    
    for (int y = 0; y <= MAX_SQUARES_IN_A_LINE; y++){
        // draw horizontal lines
         drawLine(
            GRID_POSITION_X,
            GRID_POSITION_Y + y * GRID_SIZE, 
            GRID_POSITION_X + GRID_LENGTH ,
            GRID_POSITION_Y + y * GRID_SIZE);
    }
}

void drawRobot(){
    int x = robot.x;
    int y = robot.y;
    
    // rescale
    x = GRID_POSITION_X + GRID_SIZE * x,
    y = GRID_POSITION_Y + GRID_SIZE * y,
    
    // set Robot colour to green
    setRGBColour(143,232,104);

    // draw the robot
    if (strcmp(robot.direction, "right") == 0){
        int robotX[] = {x, x, x+GRID_SIZE};
        int robotY[] = {y, y+GRID_SIZE, y+GRID_SIZE/2};
        fillPolygon (3, robotX, robotY);
   
    } if (strcmp(robot.direction, "left") == 0){
        int robotX[] = {x, x+GRID_SIZE, x+GRID_SIZE};
        int robotY[] = {y+GRID_SIZE/2, y, y+GRID_SIZE};
        fillPolygon (3, robotX, robotY);
   
    } if (strcmp(robot.direction, "up") == 0){
        int robotX[] = {x, x+GRID_SIZE/2, x+GRID_SIZE};
        int robotY[] = {y+GRID_SIZE, y, y+GRID_SIZE};
        fillPolygon (3, robotX, robotY);
   
    } if (strcmp(robot.direction, "down") == 0){
        int robotX[] = {x, x+GRID_SIZE/2, x+GRID_SIZE};
        int robotY[] = {y, y+GRID_SIZE, y};
        fillPolygon (3, robotX, robotY);
    }
}

void drawMarker(){
    // set the markers' colour to red
    setRGBColour(224,134,132);

    for (int i = 0; i < MARKER_COUNT; i ++){
        if (!marker[i].isPicked) {
                // draw Marker
                fillRect(
                    GRID_POSITION_X + marker[i].x*GRID_SIZE, 
                    GRID_POSITION_Y + marker[i].y*GRID_SIZE, 
                    GRID_SIZE, GRID_SIZE);
        }
    }
}

void drawBackground(){
    setWindowSize (WINDOW_SIZE,WINDOW_SIZE);
    background();
    drawGrid();
    drawHome();
    drawBlocks();
}

void drawObjects(){
    foreground();
    drawRobot();
    drawMarker();
}

void update(){
    // display and clear 
    sleep(TIME_LATENCY);
    clear();
    // redraw
    drawObjects();
}