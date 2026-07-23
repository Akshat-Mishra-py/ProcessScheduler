#include "scheduler.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
    int size = 10;
    struct Processes* process = ProcessGenerator(size);
    printf("%f", process[5].arrivalTime);
    NonPrimitiveScheduler(process, size, CRITERIA_BURST_TIME);   
    return 0;
}
