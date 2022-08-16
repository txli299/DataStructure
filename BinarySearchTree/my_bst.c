// Your Name Here
// Date
//
// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).

bstnode_t* createNode(int item){
    bstnode_t* newNode = (bstnode_t*)malloc(sizeof(bstnode_t));  
    if(newNode==NULL){
        exit(0);
    }
    //Assign data to newNode, set left and right children to NULL  
    newNode->data = item;  
    newNode->leftChild = NULL;  
    newNode->rightChild = NULL;  
      
    return newNode;  
} 

bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST=  malloc(sizeof(bst_t)); 
    if(myBST==NULL){
        exit(0);
    }
    myBST->size = 0;
    myBST->root = NULL;
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    if(t==NULL){
        exit(0);
    }
   if(t->size==0){
        return 1;
   }else{
       return 0;
   }
}



//Helper function, adding node to the proper place and return the root
bstnode_t* add(bstnode_t* root, int item){
    if(root == NULL){
        return createNode(item);
    }
    if(item <= root->data){
        root->leftChild = add(root->leftChild,item);
    }
    else{
        root->rightChild = add(root->rightChild,item);
    }
    return root;
}
// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
    t->root= add(t->root,item);
    t->size ++;
    if(t->root==NULL){
        return -1;
    }else{
        return 1;
    }
}


//Helper function, print the node in decending order
void dec_print(bstnode_t* start){
  if(start == NULL){
    return;
  }
  dec_print(start->rightChild);
  printf("%d\n",start->data);
  dec_print(start->leftChild);  
}

//Helper function, print the node in ascending order
void asc_print(bstnode_t* start){
    if(start == NULL){
    return;
  }
    asc_print(start->leftChild);
    printf("%d\n",start->data);
    asc_print(start->rightChild);
}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// A BST that is NULL should print "(NULL)"
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }else{
        if(order==0){
            asc_print(t->root);
        }else{
            dec_print(t->root);
        }
    }
}

//Helper function to sum the nodes
int node_sum(bstnode_t* start){
    if(start==NULL){
        return 0;
    }
    return start->data + node_sum(start->leftChild) + node_sum(start->rightChild);
}
// Returns the sum of all the nodes in the bst. 
// A BST that is NULL exits the program.
// It should run in O(n) time.
int bst_sum(bst_t *t){
    if(t==NULL){
        return 0;
    }
  return node_sum(t->root);
}



//Helper function search node but return the node if it's the node we want
int searchNode(bstnode_t* start, int value){
    if(start==NULL){
        return 0;
    }
    if(start->data==value ){
        return 1;        
    }if(start->data>value){
        return searchNode(start->leftChild,value);
    }if(start->data<value){
        return searchNode(start->rightChild,value);
    }
    return 0;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree -- exit the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    if(t==NULL){
        exit(0);
    }
    return searchNode(t->root,value);
    
}





// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if(t==NULL){
        exit(0);
    }
    return t->size;
}

//helper funciton, free all nodes;
void freeNodes(bstnode_t* start){
    if(start==NULL){
      return;
    }
    freeNodes(start->leftChild);
    freeNodes(start->rightChild);
    free(start);

    return;
  }
// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
    if(t==NULL){
        return;
    }
    freeNodes(t->root);
    free(t);
}