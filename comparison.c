/*
 * Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * Function: defines comparator functions that are to be used with qsort*/
#include <string.h>
#include "comparison.h"
/*
 * Since I ran out of time before I could implement qsort, these functions are just to show my thinking for the qsort function*/

/*
 * Comparator function for the time
 * Determines which entry has the greater time and sends them back to qsort to be swapped*/
int timeComparator(TvGuide* entry1, TvGuide* entry2)
{
    int time1 = (entry1->hour)+(entry1->minute);
    int time2 = (entry2->hour)+(entry2->minute);

    return (time1-time2);
}
/*
 * Comparator function for the name of the show
 * Determines which entry has the name with the "greater " value and sends them back to qsort to be sorted*/
int nameComparator(TvGuide* entry1, TvGuide* entry2)
{
    char** name1 = entry1->tvShow;
    char** name2 = entry2->tvShow;

    return strcmp(*name1, *name2);
}
