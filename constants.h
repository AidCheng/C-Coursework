#ifndef CONSTANTS_H
#define CONSTANTS_H

#define WINDOW_SIZE 300
#define GRID_SIZE  20
#define GRID_LENGTH  200
#define GRID_POSITION_X  50
#define GRID_POSITION_Y  50

#define MAX_SQUARES_IN_A_LINE 10

#define INIT_DIRECTION "right"
#define INIT_HOME_X 3
#define INIT_HOME_Y 6

#define TIME_LATENCY 50

int home_X = 3;
int home_Y = 4;
char initDirection[6] = "right";

static const int BLOCK_X[] = {3,4,5,6,7,8,9,4,5,8,9,4,5,8,9,0,1,2,0,1,2,2,1,2,5,6,7,8,5,6,8,6,8,5,6,7,8,9};
static const int BLOCK_Y[] = {0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,4,4,4,5,5,5,6,7,7,4,4,4,4,5,5,5,6,6,8,8,8,8,9};
static const int BLOCK_COUNT = 38;

static const int MARKERS_X[] = {7,1,1,6};
static const int MARKERS_Y[] = {1,2,6,7};
static const int MARKER_COUNT = 4;

#endif
