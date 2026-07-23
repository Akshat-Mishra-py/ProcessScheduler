#ifndef scheduler
#define scheduler

// Header for the scheduler functions.
// These functions are responsible for ordering and scheduling the processes.

void NonPrimitiveScheduler(struct Processes* p, int size, enum Criteria c);
void PrimitiveScheduler(struct Processes* p, int size, enum Criteria c);
int TimeWait(int currentTime);
#endif