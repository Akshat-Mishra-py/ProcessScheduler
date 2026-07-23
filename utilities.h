#include "ProcessManager.h"

#ifndef utilites
#define utilities

// This file provides helper utilities for choosing the next process.

// Defines the available selection criteria for choosing the next process.
enum Criteria{
    CRITERIA_BURST_TIME,
    CRITERIA_PRIORITY,
    CRITERIA_ARRIVAL_TIME
};

// Function prototype for selecting the next process based on a chosen criterion.
struct Processes nextProcess(struct Processes* p, enum Criteria c);

#endif