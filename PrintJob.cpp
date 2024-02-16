#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){} //constructor
int PrintJob::getPriority ( ){ //returns the priority of the job
    return priority;
}

int PrintJob::getJobNumber ( ){ //returns the job number
    return jobNumber;
}

int PrintJob::getPages ( ){ //returns the number of pages
    return numPages;
}
