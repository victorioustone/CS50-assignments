#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int start;
    do 
    {
        start = get_int("Start size: ");
    } 
    while (start < 9);

    // Prompt for end size
    //Prompt for start size
    int end;
    do 
    {
        end = get_int("End size: ");
    } 
    while (end <= start);

    //Calculate number of years until we reach threshold
    int years = 0;
    do
    {
        int born = start / 3;
        int pass_away = start / 4;
        years ++;
        start += (born - pass_away);
    }
    while (start < end);

    //Print number of years
    printf("Years: %i\n", years);
}