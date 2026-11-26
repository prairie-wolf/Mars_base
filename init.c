#include "sim.h"
#include <stdio.h>
#include <string.h>

int init(Basestate *base, char *base_path)
{
    //first, open the base file
    char full_path[10];
    snprinf(full_path, sizeof *full_path, "tests/%s", base_path);
    FILE *basefile = fopen(full_path, "r");
    if (basefile == NULL)
        return INIT_WRONG;
    //read line by line, initialize the baee
        /*a few further edging measure
          1 the dir:entering unwanted items or:typos
          2 missed or too much numbers
          3 numbers out of range
          4 repitive items
          5 path not exist
          6 not formatted input
such as inline order and order between lines.
As well as no newline mark or the other insertion
          we don't consider too much for now*/
    char buffer[20];
    char *reso_type[6] =
    {
    OXYGEN,
    TEMPERATURE,
    POWER,
    WATER,
    ROBOT,
    HULL
    };
    bool checked[6] = {false};
    // and the time!!!
    for (int i = 0; i < 6; i++)
    {
        fgets(buffer, sizeof buffer, stdin);
        for (int j = 0; j < 6; j++)
        {
            if s

