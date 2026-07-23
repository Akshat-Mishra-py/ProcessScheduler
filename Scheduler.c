#include "ProcessManager.h"
#include "utilities.h"
#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
// This file contains scheduler implementations.
// The current function is left empty and can be completed later.

void NonPrimitiveScheduler(struct Processes* p, int size, enum Criteria c){
    int time = 0;
    int index = nextProcess(p, size, time, c);
    while (size>=0)
    {
        if (index<=0){
            printf("CPU: Idle");
            time = TimeWait(time);
            index = nextProcess(p, size, time, c);
        }
        if ( p[index].actualBurstTime<=0 ){
            size = removeProcess(p, index, size);
            index = nextProcess(p, size, time, c);
        }
        else{
            printf("CPU: Computing Process: #", p[index].pid);
            p[index].actualBurstTime--;
            time = TimeWait(time);
        }
    }    
}
int TimeWait(int currentTime){
    currentTime++;
    Sleep(1);
    return currentTime;
}