#ifndef scheduler
#define scheduler
#include "ProcessManager.h"
#include "utilities.h"
// Header for the scheduler functions.
// These functions are responsible for ordering and scheduling the processes.

void NonPreemptiveScheduler(struct Processes* p, int size, enum Criteria c);
int TimeWait(int currentTime);
void ProcessInfo(struct Processes process);
#endif