#include "ProcessManager.h"
#include "utilities.h"
#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
// This file contains scheduler implementations.
// The current function is left empty and can be completed later.

void NonPrimitiveScheduler(struct Processes* p, int size, enum Criteria c){
    int time = 0;
    int index = nextProcess(p, size, time, c);
    while (size > 0)
    {
        printf(ORANGE "\n----------Current Time = %d------------\n" RESET, time);
        printf(YELLOW "DEBUG: index=%d size=%d arrival=%f burst=%f\n" RESET, 
                index, size, index >= 0 && index < size ? p[index].arrivalTime : 0.0f,
                index >= 0 && index < size ? p[index].actualBurstTime : 0.0f);

        if (index < 0)
        {
            printf(BLUE "CPU: Idle\n" RESET);
            time = TimeWait(time);
            index = nextProcess(p, size, time, c);
            continue;
        }

        if (p[index].actualBurstTime <= 0)
        {
            size = removeProcess(p, index, size);
            index = nextProcess(p, size, time, c);
            continue;
        }
        printf(GREEN);
        printf("======CPU: Computing Process=====\n");
        ProcessInfo(p[index]);
        printf(RESET);
        p[index].actualBurstTime--;
        time = TimeWait(time);
    }
}
int TimeWait(int currentTime){
    currentTime++;
    Sleep(100);
    return currentTime;
}
void ProcessInfo(struct Processes process){
    printf("Process #%d |\t Arrival Time : %f |\nBurst Time : %f |\nPredicted Burst Time : %d\n", process.pid, process.arrivalTime, process.actualBurstTime, process.processType);
}