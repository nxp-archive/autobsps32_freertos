void* InterruptsTable[1024] __attribute__ ((section ("interruptTable")));

void vInitInterruptTable(int id, void* vector)
{
    InterruptsTable[id] = vector;
}