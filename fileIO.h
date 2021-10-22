/*
 * Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * This file contains function prototypes for fileIO.c
 * This file also includes the data.h file since the methods need the struct located within this .h file*/
#include "data.h"

/*
 * Descriptions for these methods are located within the fileIO.c file*/
TvGuide** readFile(char* filename);
void writeFile(TvGuide** sortedArray, char* outputFile);
