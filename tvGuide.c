/*Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * Function: Entry point of the whole program*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"
#include "linkedList.h"
#include "interface.h"
/*The main function is the entry point of the program.
 *It takes in two command line parameters. An input file and an output file
 *If user doesn't input exactly two command line parameters, an error statement is printed
 *Gets user input for the day and the sorting method(Name or Time)
 *Entries in the array are filtered by checking if the day variable is equal to a particular day and then printing that entry to the screen and output file*/
int main(int argc, char* argv[])
{ 
    int ii;
    char* optionDay = NULL;
    char* optionSort = NULL;
    TvGuide** tvGuideArray = NULL;
    
    if(argc!=3)
    {
        printf("Invalid number of command line arguments");
    }
    else
    {
        optionDay = userInputDay();
        optionSort = userInputSort();
        tvGuideArray = readFile(argv[1]);

        for(ii=0;ii<sizeof(tvGuideArray);ii++)
        {
            if(strcmp(tvGuideArray[ii]->day, optionDay)==0)
            { 
                printf("%d:%d - %s", tvGuideArray[ii]->hour, tvGuideArray[ii]->minute, tvGuideArray[ii]->tvShow);
            }
        }
        writeFile(tvGuideArray, argv[2]);
        free(tvGuideArray);
    }
    return 0;        
}


