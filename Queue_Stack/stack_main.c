// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
int unitTest1(){
    int passed = 0;
    
    stack_t* test_s = create_stack(32);
    if(32==test_s->capacity){
        passed =1;
    }
    free_stack(test_s);
    return passed;

}
int unitTest2(){
	int passed = 0;
	stack_t* test_s = create_stack(32);
	stack_enqueue(test_s,1);
    stack_enqueue(test_s,2);
    stack_enqueue(test_s,3);
    stack_enqueue(test_s,4);
    stack_enqueue(test_s,5);
    stack_enqueue(test_s,6);
    stack_enqueue(test_s,7);
    stack_enqueue(test_s,8);
    stack_enqueue(test_s,9);
    stack_enqueue(test_s,10);
	if(10==stack_size(test_s)){
        passed =1;
    }	

	free_stack(test_s);
	return passed;
}

int unitTest3(){
    int passed = 0;
    
    stack_t* test_s = create_stack(32);
    int i =0;
    for(i=0; i < 32; i++){
        stack_enqueue(test_s,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test_s);
    }
    
    if(0==stack_size(test_s)){
        passed =1;
    }

    free_stack(test_s);

    return passed;
}

int unitTest4(){
    int passed = 0;
    
    stack_t* test_s = create_stack(32);
    int i =0;
    for(i=0; i < 32; i++){
       stack_enqueue(test_s,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test_s);
    }
    for(i=0; i < 32; i++){
        stack_enqueue(test_s,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test_s);
    }
    if(0==stack_size(test_s)){
        passed =1;
    }
    
    free_stack(test_s);

    return passed;
}
int unitTest5(){
    int passed = 0;
    
    stack_t* test_s = create_stack(1);
    stack_enqueue(test_s,1);
    if(1==stack_full(test_s)){
        passed = 1;
    }else{
        free_stack(test_s);
        return 0;
    }
    
    stack_dequeue(test_s);
    if(0==stack_full(test_s)){
        passed = 1;
    }else{
        passed = 0;
    }
       
    free_stack(test_s);

    return passed;
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	printf("Case1 passed: %d\n",unitTest1());
	printf("Case2 passed: %d\n",unitTest2());
	printf("Case3 passed: %d\n",unitTest3());
	printf("Case4 passed: %d\n",unitTest4());
	printf("Case5 passed: %d\n",unitTest5());
	return 0;
}
