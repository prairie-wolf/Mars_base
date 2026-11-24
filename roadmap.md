# ROADMAP: A WALKTHROUGH

## for each time split
0. before that, make sure have a valid basestate
- get string constants from cli and store them
1. apply events
- get one event from target file
for that I will need a FILE ptr that read from the file(we need at least a file name to do that cause fopen requires that)
- judge whether qualified event, based on some conditional syntax, and the options are finite
- if qualified, then abuse the coordinate effect and change basestate
2. read actions
- get one action from the target file
and so so
- judge, just as 1
    3. check status
    - check the basestate to see if action is execuable
    4. decide whether actions succeed
    - just as the description
5. update status
- 
6. calculate current status,
7. next round or died
8. if the task failed, give back the reason(and sourse?)