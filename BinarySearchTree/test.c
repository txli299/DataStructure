
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free


#include "my_bst.h"
#include "my_bst.c"
// Testing allocation
int main(){
    int result,sum,size;
    bst_t * testBST = bst_create();
    bst_add(testBST,78);
    bst_add(testBST,79);
    bst_add(testBST,77);
    bst_print(testBST,1);
    size = bst_size(testBST);
    result = bst_find(testBST,75);

    //sum = bst_sum(testBST);
    bst_free(testBST);    
    //free(testBST);
    printf("%d\n",result);
    printf("%d\n",size);
    //printf("%d\n",sum);


    return 0; 
}
