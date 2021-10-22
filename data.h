/*
 * Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * This is the struct I designed which I thought would be appropriate*/

/*
 * This struct defines a single entry for a tv show
 * It contains a string for the name of the tvShow
 * A string for the day the show is meant to air
 * an int to represent the hour segment of its show time
 * an int to represent the minute segments of its show time*/
typedef struct
{
    char* tvShow;
    char* day;
    int hour;
    int minute;
}TvGuide;
