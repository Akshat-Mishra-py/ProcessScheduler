#include <stdlib.h>
#include <math.h>
#include "utilities.h"

// This function selects a process according to the requested selection criterion.
// It compares values across the process array and returns the process index with the minimum value.
int nextProcess(struct Processes* p, int size,int CurrentTime, enum Criteria c){
    // Starts with an extremely large value so the first process becomes the initial minimum.
    float timeComparator = INFINITY;
    struct Processes* nextProcess;
    int index= -1;

    // Scan all processes and choose the one that best fits the selected rule.
    for (size_t i = 0; i < size; i++)
    {
        if (p[i].arrivalTime<CurrentTime) { continue; }

        switch (c)
        {
            case CRITERIA_BURST_TIME:
                if(p[i].processType < timeComparator){
                    *nextProcess = p[i];
                    timeComparator = p[i].processType;
                    index = i;
                }
                break;
            case CRITERIA_ARRIVAL_TIME:
                if(p[i].arrivalTime < timeComparator){
                    *nextProcess = p[i];
                    timeComparator = p[i].arrivalTime;
                    index = i;

                }
            default:
                if(p[i].priorityNumber < timeComparator){
                    *nextProcess = p[i];
                    timeComparator = p[i].priorityNumber;
                    index = i;
                }
                break;
        }   
    }
    return index;
}
int removeProcess(struct Processes* processArray,int index, int size){
    if(index<=0 || index >= size ) {return size;}
    processArray[index] = processArray[size-1]; //set to last process to replace the current one 
    return size-1;
}
