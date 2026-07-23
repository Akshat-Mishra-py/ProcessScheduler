#ifndef utilites
#define utilities
#include "ProcessManager.h"

// This file provides helper utilities for choosing the next process.
// Defines the available selection criteria for choosing the next process.
enum Criteria{
    CRITERIA_BURST_TIME,
    CRITERIA_PRIORITY,
    CRITERIA_ARRIVAL_TIME
};

// Function prototype for selecting the next process based on a chosen criterion.
int nextProcess(struct Processes* p, int size, int CurrentTime, enum Criteria c);
int removeProcess(struct Processes* processArray, int index, int size);

#endif