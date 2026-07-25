#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utilities.h"
#include "scheduler.h"


// This function selects a process according to the requested selection criterion.
// It compares values across the process array and returns the process index with the minimum value.
int nextProcess(struct Processes *p, int size, int CurrentTime, enum Criteria c)
{
    // Starts with an extremely large value so the first process becomes the initial minimum.
    float timeComparator = INFINITY;
    int index = -1;

    // Scan all processes and choose the one that best fits the selected rule.
    for (size_t i = 0; i < size; i++)
    {
        if (p[i].arrivalTime > CurrentTime)
        {
            // printf("-----------\n\nProcess %d -> skipped | Arrival Time : %f | Current Time : %d\n\n---------",p[i].pid, p[i].arrivalTime,CurrentTime);
            continue;
        }

        switch (c)
        {
        case CRITERIA_BURST_TIME:
            if (p[i].processType < timeComparator)
            {
                timeComparator = p[i].processType;
                index = i;
            }
            break;
        case CRITERIA_ARRIVAL_TIME:
            if (p[i].arrivalTime < timeComparator)
            {
                timeComparator = p[i].arrivalTime;
                index = i;
            }
            break;
        default:
            if (p[i].priorityNumber < timeComparator)
            {
                timeComparator = p[i].priorityNumber;
                index = i;
            }
            break;
        }
    }
    return index;
}
int removeProcess(struct Processes *processArray, int index, int size)
{
    if (index < 0 || index >= size)
    {
        printf(RED "------ Invalid process delete request: index %d --------\n"RESET, index);
        return size;
    }

    printf(RED "-------- Process Completed --------\n");
    ProcessInfo(processArray[index]);
    printf("======== Process Completed ========\n" RESET);

    processArray[index] = processArray[size - 1]; // set to last process to replace the current one
    return size - 1;
}
