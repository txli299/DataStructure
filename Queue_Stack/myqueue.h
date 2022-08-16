/*
*****************************************
*		Tuoxin Li 06/04/2022			*
*		queue functions					*
*		All test passed					*
*										*
*****************************************/
#include <stdlib.h>
#ifndef MYQUEUE_H
#define MYQUEUE_H

// The main data structure for the queue
struct queue{
	unsigned int back;	    // The next free position in the queue
				    		// (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
				    		// (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		    	// The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;


queue_t* create_queue(unsigned int _capacity){
	queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
	myQueue->capacity = _capacity; //capacity of the queue
	myQueue->data = (int*)malloc(sizeof(int)*myQueue->capacity); //using heap to store data
	myQueue->size = 0; //curent size
	myQueue->back = 0; 
	myQueue->front = 0;

	return myQueue;
}
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has data in it)
int queue_empty(queue_t* q){
	if(q->size == 0){
		return 1; 
	} else{
		return 0;
	}
}

// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q){
	if(q->size == q->capacity){
		return 1;
	} else{
	return 0;
	}
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t* q, int item){
	if(queue_full(q)==1){
		return -1; // Note: you should have two return statements in this function.
	}
	q->data[q->back] = item;
	q->size +=1;
	q->back = (q->back + 1) % q->capacity;
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
int queue_dequeue(queue_t *q){
	if(queue_empty(q)==1){
		exit(1);
	}
	int result = q->data[q->front];
	q->front=(q->front + 1) % q->size;
	q->size -=1;
	return result; 
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL queue cannot return the size, call exit(1))
unsigned int queue_size(queue_t* q){
	if(q == NULL){
		exit(1);
	}
	return q->size;
}

// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
	if(q==NULL){
		return;
	}
	if(q->data==NULL){
		free(q);
	}else{
		free(q->data);
		free(q);
	}
}


#endif

