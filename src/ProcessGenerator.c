#include "ProcessManager.h"
#include <stdlib.h>

// This function creates an array of processes and fills each one with values.
struct Processes* ProcessGenerator(int size){
    // Allocates memory for the requested number of processes.
    struct Processes* p = (struct Processes*)malloc(size * sizeof(struct Processes));
    float time = 0 ;

    // A pool of available process types from which random values are selected.
    enum ProcessesType processPool[] = {IO, COMPUTE, LIGHTCOMPUTE};
    int totalElements = sizeof(processPool)/sizeof(processPool)[0];
    int randomindx = rand()%totalElements;

    // Fill each process with generated values.
    for (size_t i = 0; i < size; i++)
    {
        p[i].pid = i; // Each process gets a simple sequential ID.
        p[i].arrivalTime = time + (rand()%2)+1; // Arrival time is randomized.
        time = time + p[i].arrivalTime; // Keeps track of cumulative time.
        p[i].processType = processPool[randomindx]; // Assigns a random process category.
        p[i].actualBurstTime = p[i].processType+(rand()%3); // Burst time is derived from type plus a small random value.
        p[i].priorityNumber = i; // Priority is initially set to the index value.
    }
    return p;
} 