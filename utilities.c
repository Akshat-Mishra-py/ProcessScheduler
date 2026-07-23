#include <stdlib.h>
#include <math.h>
#include "utilities.h"

// This function selects a process according to the requested selection criterion.
// It compares values across the process array and returns the process with the minimum value.
struct Processes nextProcess(struct Processes* p, int size, enum Criteria c){
    // Starts with an extremely large value so the first process becomes the initial minimum.
    float timeComparator = INFINITY;
    struct Processes nextProcess;

    // Scan all processes and choose the one that best fits the selected rule.
    for (size_t i = 0; i < size; i++)
    {
        switch (c)
        {
            case CRITERIA_BURST_TIME:
                if(p[i].processType < timeComparator){
                    nextProcess = p[i];
                    timeComparator = p[i].processType;
                }
                break;
            case CRITERIA_ARRIVAL_TIME:
                if(p[i].arrivalTime < timeComparator){
                    nextProcess = p[i];
                    timeComparator = p[i].arrivalTime;
                }
            default:
                if(p[i].priorityNumber < timeComparator){
                    nextProcess = p[i];
                    timeComparator = p[i].priorityNumber;
                }
                break;
        }   
    }
    return nextProcess;
}