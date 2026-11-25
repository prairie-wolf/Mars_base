#include <string.h>
#include "sim.h"

#define num_of_arg 9

int input(char *argv[], int index[])
{
    const char *identifier[4] = {"--base", "--events", "--actions", "--output"};
    for (int i = 1; i < 9; i += 2)
    {
        bool matched = false;
        for (int j = 0; j < 4; j++)
        {
            if (strcmp(argv[i], identifier[j]) == 0)
            {
                index[j] = i;
                matched = true;
            }
        }
        
        if (!matched)
        {
            return INPUT_WRONG;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j && index[i] == index[j])
            {
                return INPUT_WRONG;
            }
        }
    }

    return PASSED;
}