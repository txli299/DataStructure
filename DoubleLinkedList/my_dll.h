// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#include <stdio.h> //for checking
#include <stdlib.h> // for malloc/free
# include <string.h>
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node {
	int data;
	struct node* next;
  	struct node* previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL {
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
    node_t * tail;          //tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
	dll_t* myDLL= (dll_t*)malloc(sizeof(dll_t));	
	
	if (myDLL==NULL){
		return NULL;//return null if couldnt allocate memory
	}
	myDLL->count=0;
	myDLL->head=NULL;//Should be no tail and tail
	myDLL->tail=NULL;	
	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l){
	if(l==NULL){
		return -1;
	} if(l->count==0){
		return 1;
	} else{//when there is at least 1 element
		return 0;
	}

}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
	if(l==NULL){
		return -1;
	}
	node_t* node = (node_t*)malloc(sizeof(node_t));
	memset(node, 0, sizeof(node_t));
	if(node == NULL){//when couldn't allocate memory
		return 0;
	}
	node->data=item;
	if(l->head==NULL){//when there is no head
		l->head=node;
		l->tail=node;
		l->count++;
		return 1;
	} else{
		node->next=l->head;
		l->head->previous=node;
		l->head = node;
		l->count++;
		return 1;
	}
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
	if(l==NULL){
		return -1; 
	}
	node_t* node = (node_t*)malloc(sizeof(node_t));
	memset(node, 0, sizeof(node_t));
	if(node == NULL){//when couldn't allocate memory
		return 0;
	}
	node->data=item;
	if(l->tail==NULL){//when there is no tail
		l->head=node;
		l->tail=node;
		l->count++;
		return 1;
	}else{
		node->previous=l->tail;
		l->tail->next=node;
		l->tail=node;
		l->count++;
		return 1;
	}
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL. 
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* l){
	if(l==NULL){
		return -1; // Note: This line is a 'filler' so the code compiles.
	}
	if(l->head==NULL){
		return 0;
	}
	int data = l->head->data;
	if(l->head->next==NULL){//when there is only 1 element in the list
		l->head=NULL;
		free(l->head);
		l->count--;
		return data;
	} else{
		node_t* temp = l->head;
		l->head->next->previous=NULL;
		l->head = l->head->next;
		free(temp);
		l->count--;
		return data;
	}
}	

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL. 
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* l){
	if(l==NULL){
		return -1; // Note: This line is a 'filler' so the code compiles.
	}
	if(l->tail==NULL){
		return 0;
	}
	int data =l->tail->data;
	if(l->tail->previous==NULL){//when there is only one element in the list
		l->tail=NULL;
		free(l->tail);
		l->count--;
		return data;
	} else{
		node_t* temp = l->tail;
		l->tail->previous->next = NULL;
		l->tail = l->tail->previous;
		free(temp);
		l->count--;
		return data;
	}
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t* l, int pos, int item){
	if(l==NULL){
		return -1; // Note: This line is a 'filler' so the code compiles.
	} 
	if(pos<0){//position is negatiive
		return 0;
	}
	if(pos>= l->count ){//position larger than size
		return 0;
	}
	
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if(node == NULL){//when couldn't allocate memory
		return 0;
	}
	node->data=item;
	node_t* temp = l->head;
	while(pos !=0){
		temp=temp->next;
		pos--;
	}
	node->next=temp;
	temp->previous->next=node;
	node->previous=temp->previous;
	temp->previous=node;
	l->count++;
	return 1;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	if(pos<0){//position is negatiive
		return 0;
	}
	if(pos>= l->count ){//position larger than size
		return 0;
	}
	if(l==NULL){
		return -1; // Note: This line is a 'filler' so the code compiles.
	}
	node_t* temp = l->head;
	while(pos !=0){
		temp=temp->next;
		pos--;
	}
	return temp->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){
	if(l==NULL){
		return -1; 
	}
	if(pos<0){//position is negatiive
		return 0;
	}
	if(pos>= l->count ){//position larger than size
		return 0;
	}
	if(pos==0){
		return dll_pop_front(l);
		
	}
	if(pos==l->count-1){
		return dll_pop_back(l);
		
	}

	node_t* temp = l->head;	
	while(pos!=0){
		temp=temp->next;
		pos--;
	}
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	free(temp);
	l->count--;
	return 1;
}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t* l){
	if(l==NULL){
		return -1; // Note: This line is a 'filler' so the code compiles.
	} else{
		return l->count;
	}
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* l){
	if(l==NULL){
		return;
	}
	if(l->head == NULL){
		free(l);
		return;
	}	
	else{
		node_t* temp = l->head;
		while(temp!=NULL){
			l->head=temp;
			temp = l->head->next;
			free(l->head);
		}
		free(l);
		return;
	}
}



#endif
