// Urban Pistek (20802700) and Julia Baribeau (20792386)

#include "lab3_priority_queue.hpp"
#include <iostream>

using namespace std;

// PURPOSE: Parametric constructor
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	heap = new TaskItem* [n_capacity + 1];
	capacity = n_capacity;
	size = 0;
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
    for (unsigned int i = 1; i <= size; ++i) {
        if (heap[i]) {
            delete heap[i];
            heap[i] = NULL;
        }
    }
    delete [] heap;
    size = 0;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return size == 0;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return size == capacity;
}

// PURPOSE: Prints the contents of the priority queue; format not specified
//Print in the order of the array
void PriorityQueue::print() const {
	for(unsigned int idx = 1; idx <= size; idx++){
		cout << "Priority: " << heap[idx]->priority << '\t' << " Description: " << heap[idx]->description << endl;
	}
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")

// Double check that the function implementation is correct
PriorityQueue::TaskItem PriorityQueue::max() const {
	//Not sure if need to check that the first item is actually the max item
	if(size == 0)
		return TaskItem(-1, "NULL");
	else
	{
		return *heap[1];//Brackets already dereference, so is there a need to dereference here?
		//Should the max be at index 1?
	}
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
    if(size == capacity){
        return false;
    }
    if(size == 0){
        heap[1] = new TaskItem(val.priority, val.description);
    }
    else{
        int idx = size+1;
        heap[idx] = new TaskItem(val.priority, val.description);
        while(idx > 1 && heap[idx/2]->priority < heap[idx]->priority){
            TaskItem* temp = heap[idx];
            heap[idx] = heap[idx/2];
            heap[idx/2] = temp;
            idx = idx/2;
        }
    }
    ++size;
	return true;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {

    if(size == 0){
        return false;
    }

    delete heap[1];
    heap[1] = heap[size];
    unsigned int index = 1;
    bool balanced = false;
    while(2*index <= size && index >=1 && !balanced){
        int max_index;
        if(2*index == size)
            max_index = 2*index;
        else{
            if(heap[2*index]->priority >= heap[2*index+1]->priority)
                max_index = 2*index;
            else
                max_index = 2*index+1;
        }
        if(heap[max_index]->priority > heap[index]->priority){
            TaskItem* temp = heap[max_index];
            heap[max_index] = heap[index];
            heap[index] = temp;
            index = max_index;
        }
        else
            balanced = true;
    }
    heap[size] = NULL;
    --size;
    return true;

	/*if(size == 0){
		cout << "Empty Heap" << endl;//For debugging
		return false;
	}
	else if (size == 1){
		delete heap[1];
	}
	else{
		delete heap[1];
		heap[1] == heap[size];
		cout<<"111111111111"<<endl;
		unsigned int index = 1;
		bool balanced = false;
		while(!balanced && index >=1 && 2*index <= size){
			int max_index;
			if(2*index == size){
				max_index = 2*index;
			}
			else if(heap[2*index]->priority >= heap[2*index+1]->priority){
				max_index = 2*index;
			}
			else{
				max_index = 2*index+1;
			}
			if(heap[max_index]->priority > heap[index]->priority){
				TaskItem* temp = heap[max_index];
				heap[max_index] = heap[index];
				heap[index] = temp;
				index = max_index;
			}
			else{
				balanced = true;
			}
		}
		cout<<"222222222"<<endl;
	}
	heap[size] = NULL;
	--size;
	return true;*/
}
