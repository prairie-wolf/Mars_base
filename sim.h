#ifndef SIM_H
#define SIM_H

#include <stdbool.h>

// remember to change the variable name to lowercase
typedef struct {
    int TIME;    // 1 to 72
    int POWER;   // reset if under 0
    int OXYGEN;  // reset if under 0
    int WATER;   // reset if under 0
    int TEMPERATURE;   // can be under 0 but deadly
    int HULL;          // 0 to 100
    int ROBOT;         // not negative
    bool ACTIVE_ROBOT; // bool
    int REPAIRED;      // record effective repairs
    int FAILED_ACTION; // record failed actions
    
    bool RESULT;       // ? success : failure
    int SCORE;         // integer
    // the above have to appear in the output
} BaseState;

typedef struct {
    // other env status
    bool commu_lose;
    bool oxy_leak;
    bool sol_fault;
    bool lab_close;
} env;


typedef enum {
    INVALID = -1,
    EXCEPTION,
    PASSED,
    INPUT_WRONG,
    INIT_WRONG,
    EVENTS_WRONG,
    ACTIONS_WRONG


} RaiseError;

int input(char *argv[], int index[]);
int init(BaseState *base, char *base_path);
int events(BaseState *base, char *events_path, env environment);
int actions(BaseState *base, char *actions_path, env environment);
void update_state(BaseState *base, env environment);
void game_judge(BaseState *base);
int cal_score(BaseState *base);
int output(BaseState *base);

#endif
