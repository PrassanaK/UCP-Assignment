/*Name: Prassana Kamalakannan
 * DateModified: 27/05.18
 * Function reading and writing to files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"
#include "linkedList.h"

/*readFile imports a string as a filename(argv[1])
 *each entry of input file has two lines: Name of the show, and the date and time of the show
 * Show name is read in first and then the date and time right after
 * Each element that is read in is assigned to a variable in a Struct called TvGuide(data.h) that holds each entry
 * Each entry is then inserted into a linkled list
 * This process will loop until end of file is reached
 * Each element in the linked list is then placed into an array which is then exported*/
TvGuide** readFile(char* filename)
{
    TvGuide* tvGuide;
    TvGuide** tvGuideArray;
    LinkedList* list = NULL;
    int hour, minute;
    int ii = 0;
    int jj = 0;
    int count = 0;
    char* day = NULL;
    char* tvShow = NULL;

    FILE* f = NULL;

    f = fopen(filename, "r");

    if(f==NULL)
    {
        perror("File did not open properly\n");
    }
    else
    {
        do
        {
            tvGuide = (TvGuide*)malloc(sizeof(TvGuide));
            tvShow = (char*)malloc(30*sizeof(char));
            day = (char*)malloc(12*sizeof(char));
            
            fgets(tvShow, 30, f);
            fscanf(f, "%s %d:%d", day,  &hour, &minute);

            (tvGuide->tvShow)=tvShow;
            (tvGuide->day)=day;
            (tvGuide->hour)=hour;
            (tvGuide->minute)=minute;
 
            insertFirst(list, tvGuide);

            count++;
        }while(!feof(f));
                     
        tvGuideArray = (TvGuide**)malloc(count*sizeof(TvGuide*));
        for(ii=0;ii<count;ii++)
        {
            tvGuideArray[ii] = (TvGuide*)retrieveElement(list, ii);
        }

        for(jj=0;jj<count;jj++)
        {
            free(day);
            free(tvShow);
            free(tvGuide);
        }
    }
    fclose(f);
    freeLinkedList(list);
    return tvGuideArray;
    
}

/*
 * writeFile imports an array of pointers and a string that is the outputfile(argv[2])
 * an entry is written to a file in the format: 'hour:minute - nameOfTvShow'
 * each attribute of an entry is extracted from a TvGuide struct the and element of sortedArray points to*/
void writeFile(TvGuide** sortedArray, char* outputFile)
{
    FILE* fo = fopen(outputFile,"w");
    int ii;

    for(ii=0;ii<sizeof(sortedArray);ii++)
    {
        fprintf(fo, "%d:%d - %s", sortedArray[ii]->hour, sortedArray[ii]->minute, sortedArray[ii]->tvShow);
    }

    fclose(fo);
}


