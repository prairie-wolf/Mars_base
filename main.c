// at this stage, we want at least to implement the minimal version that can run through one single time clip
#include <stdio.h>
#include "sim.h"
// macro substition
#define num_of_arg 9

int main(int argc, char *argv[])
{
// module: legal input
    
    // handle the arguments that cli passing in
    if (argc != num_of_arg)
    {
        printf("Invalid command line arguments.\n");
        return INPUT_WRONG;
    }

    // 0: base, 1: events, 2: actions, 3, output
    int argv_index[4];
    if (input(argv, argv_index) != PASSED)
    {
        return INPUT_WRONG;
    }

    // initialization
    BaseState base = {0};
    env environment = {false};
    if (init(&base, argv[argv_index[2]]) != PASSED) {return INIT_WRONG;}

    //by now, the program should have a valid inital base state
    
// module: apply the event
    if (events(&base, argv[argv_index[0]], environment) != PASSED) {return EVENTS_WRONG;}
// module: read actions
    if (actions(&base, argv[argv_index[1]], environment) != PASSED) {return ACTIONS_WRONG;}

    // now that all input being collected, update the status
// module: update status
    update_state(&base, environment);
// module: decide the split fails or not
    game_judge(&base);
// module: calculate the score
    cal_score(&base);
// module: print the result
    if (output(&base) != PASSED) {return EXCEPTION;}
}
