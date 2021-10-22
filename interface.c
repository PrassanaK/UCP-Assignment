/*
 * Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * Function provides user input for sorting and filtering*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

/*
 * userInputDay imports nothing and exports a string(week day)
 * function asks user to input any day of the week.
 * Input validation ensures that if the user enters anything other than a day of the week, an error statement will print to screen and the whole process will loop until valid input is entered
 * the value returned from this function is assigned to optionDay in tvGuide.c*/
char* userInputDay()
{
    char* day = NULL;
    char* option = NULL;
    day = (char*)malloc(12*sizeof(char));
    
    do
    {
        printf("Enter a day\n");
        scanf("%s", day);

        if((strcmp(day, "Monday")!=0)||(strcmp(day, "Tuesday")!=0)||(strcmp(day, "Wednesday")!=0)||(strcmp(day, "Thursday")!=0)||(strcmp(day, "Friday")!=0)||(strcmp(day, "Saturday")!=0)||(strcmp(day, "Sunday")!=0))
        {
            printf("Please enter a day of the week\n");
        }
        else
        {
            option = day;
        }
    }while((strcmp(day, "Monday")!=0)||(strcmp(day, "Tuesday")!=0)||(strcmp(day, "Wednesday")!=0)||(strcmp(day, "Thursday")!=0)||(strcmp(day, "Friday")!=0)||(strcmp(day, "Saturday")!=0)||(strcmp(day, "Sunday")!=0));
    free(day);
    return option;
}

/*
 * userInputSort imports nothing and exports a string(time or name)
 * function asks user to input a method by which the TvGuide array should be sorted(by time or by name
 * Input validation ensures that if the user enters anything other than a sorting method, then an error message will print to screen and the whole process will loop until valid input is entered
 * value returned from this function is assigned to optionSort in tvGuide.c*/
char* userInputSort()
{
    char* sortingMethod = NULL;
    char* option;
    sortingMethod = (char*)malloc(30*sizeof(char));
    do
    {
        printf("Enter a sorting method\n");
        scanf("%s", sortingMethod);

        if((strcmp(sortingMethod, "name")!=0)||(strcmp(sortingMethod, "time")!=0))
        {
            printf("Please enter a valid sorting method\n");
        }
        else
        {
            option = sortingMethod;
        }
    }while((strcmp(sortingMethod, "name")!=0)||(strcmp(sortingMethod, "time")!=0));
    free(sortingMethod);
    return option;
}
