// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest0(){

	queue_t* test1 = create_queue(1);
	queue_enqueue(test1,1);	

	free_queue(test1);
	//free(test1->data);
	//free(test1);
}

int unitTest1(){
    int passed = 0;
    queue_t* testq = create_queue(30);
    if(30==testq->capacity){
        passed = 1;
    }
    free_queue(testq);
    
    return passed;
}
// Tests adding multiple items to a queue
int unitTest2(){
    int passed = 0;

    queue_t* testq = create_queue(10);
    queue_enqueue(testq,1);
    queue_enqueue(testq,2);
    queue_enqueue(testq,3);
    queue_enqueue(testq,4);
    queue_enqueue(testq,5);
    queue_enqueue(testq,6);
    queue_enqueue(testq,7);
    queue_enqueue(testq,8);
    queue_enqueue(testq,9);
    queue_enqueue(testq,10);
    if(10==queue_size(testq)){
        passed = 1;
    }

    free_queue(testq);

    return passed;
}
// Tests enqueing and dequeing
int unitTest3(){
    int passed = 0;

    queue_t* testq = create_queue(32);
    int i =0;
    for(i=0; i < 32; i++){
        queue_enqueue(testq,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(testq);
    }
    
    if(0==queue_size(testq)){
        passed =1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing multiple times
int unitTest4(){
    int passed = 0;
    
    queue_t* testq = create_queue(32);
    int i =0;
    for(i=0; i < 32; i++){
        queue_enqueue(testq,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(testq);
    }
    for(i=0; i < 32; i++){
        queue_enqueue(testq,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(testq);
    }
    
    if(0==queue_size(testq)){
        passed =1;
    }
    
    free_queue(testq);

    return passed;
}

int unitTest5(){
    int passed = 0;

    queue_t* testq = create_queue(1);
    queue_enqueue(testq,1);
    if(1==queue_full(testq)){
        passed = 1;
    }else{
	    free_queue(testq);
	return 0;
    }
    
    queue_dequeue(testq);
    if(0==queue_full(testq)){
        passed = 1;
    }else{
        passed = 0;
    }
    
    free_queue(testq);

    return passed;
}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	//unitTest0();
	printf("Case1 passed: %d\n",unitTest1());
	printf("Case2 passed: %d\n",unitTest2());
	printf("Case3 passed: %d\n",unitTest3());
	printf("Case4 passed: %d\n",unitTest4());
	printf("Case5 passed: %d\n",unitTest5());
}
