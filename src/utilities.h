#ifndef utilities

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#define ORANGE  "\033[38;5;208m"
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