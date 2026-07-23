#ifndef ProcessManager
#define ProcessManager

// Different process categories with predefined burst-time values.
enum ProcessesType{
    IO=7,
    COMPUTE=5,
    LIGHTCOMPUTE=2
};
// This file defines the data structure used to represent a process
// and the types of process categories that can be generated.

// Represents one process in the scheduler system.
struct Processes{
    unsigned int pid; // Unique process identifier.
    float arrivalTime; // Time when the process enters the system.
    float actualBurstTime; // The real burst time of the process.
    enum ProcessesType processType; // Used by the scheduler to estimate burst behavior.
    float priorityNumber; // Priority value assigned to the process.
};


// Function prototype for generating a list of processes.
struct Processes* ProcessGenerator(int size);

#endif