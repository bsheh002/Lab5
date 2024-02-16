#include "Heap.h"
#include <iostream>
using namespace std;
Heap::Heap() {
    numItems = 0;
}
void Heap::enqueue(PrintJob* job) { //enqueues the heap using a print job
    if (numItems == MAX_HEAP_SIZE) { //checks if heap is full
        cout << "Heap is full, cannot enqueue." << endl;
        return;
    }
    int index = numItems;
    arr[index] = job;
    ++numItems;
    while (index > 0 && arr[index]->getPriority() > arr[(index - 1) / 2]->getPriority()) { //checks to see if the priority of the index is less than the priority at the middle of the array
        swap(arr[index], arr[(index - 1) / 2]); //swaps the two values
        index = (index - 1) / 2;
    }
}
void Heap::trickleDown(int index) { //using an index, trickles down the heap
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < numItems && arr[left]->getPriority() > arr[largest]->getPriority()) //checks which has a higher priority
        largest = left;
    if (right < numItems && arr[right]->getPriority() > arr[largest]->getPriority()) //checks which has a higher priority
        largest = right;
    if (largest != index) { //checks if the index is the largest value
        swap(arr[index], arr[largest]);
        trickleDown(largest);
    }
}
void Heap::dequeue() { //dequeues the heap
    if (numItems == 0) { //checks if heap is empty
        cout << "Heap is empty, cannot dequeue." << endl;
        return;
    }
    cout << "Dequeue: ";
    cout << "Priority: " << arr[0]->getPriority()
         << ", Job Number: " << arr[0]->getJobNumber()
         << ", Number of Pages: " << arr[0]->getPages() << endl;
    delete arr[0]; //deletes a value
    --numItems;
    arr[0] = arr[numItems];
    arr[numItems] = nullptr;
    trickleDown(0);
}
PrintJob* Heap::highest() { //finds the highest priority job
    if (numItems == 0) { //checks if heap is empty
        cout << "Heap is empty, no highest priority job." << endl;
        return nullptr;
    }
    return arr[0]; //returns the first value in array
}
void Heap::print() { //prints the heap
    if (numItems == 0) { //checks if heap is empty
        cout << "Heap is empty, nothing to print." << endl;
        return;
    }
    cout << "Highest Priority Job: ";
    cout << "Priority: " << arr[0]->getPriority()
         << ", Job Number: " << arr[0]->getJobNumber()
         << ", Number of Pages: " << arr[0]->getPages() << endl;
}
