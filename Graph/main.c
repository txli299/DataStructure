// Your Name Here
// Date
//
// Compile this assignment with: gcc -Wall main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"


// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

int main(int argc, const char * argv[]) {

    graph_t * graph = create_graph();

    graph_add_node(graph, 1);
    graph_add_node(graph, 1);
    graph_add_node(graph, 2);
    graph_add_node(graph,3);
    graph_add_node(graph,4);

    graph_add_edge(graph,1,3);
    graph_add_edge(graph,1,4);
    graph_add_edge(graph,2,1);
    graph_add_edge(graph,2,4);
    graph_add_edge(graph,3,2);


    //Check if node 1 have outNeighbors 3 and 4, and if node 1 hahve inNeighbor 2
    graph_node_t* node1 = find_node(graph,1);
    dll_t * nodeInNeighbors = node1->inNeighbors;
    dll_t * nodeOutNeighbors = node1->outNeighbors;
    graph_node_t* inNeighbor1=nodeInNeighbors->head->data;
    graph_node_t* outNeighbor1=nodeOutNeighbors->head->data;
    graph_node_t* outNeighbor2=nodeOutNeighbors->head->next->data;
    printf("Node1 has inNeighbors: 2==%d\n", inNeighbor1->data);
    printf("Node1 has outNeighbors: 3==%d, 4==%d\n", outNeighbor1->data,outNeighbor2->data);
    
    //test add edges
    printf("total nodes: 4==%d\n", graph_num_nodes(graph));
    printf("total edges: 5==%d\n", graph_num_edges(graph));
    int countainEdge1 = contains_edge(graph,1,3);
    printf("countainEdge result is: 1 == %d\n", countainEdge1);

    //Test remove edges
    int result1 = graph_remove_edge(graph,1,3);
    int result2 = graph_remove_edge(graph,3,2);
    printf("result1 is 1==%d, result 2 is 1==%d\n", result1,result2);
    int countainEdge2 = contains_edge(graph,1,3);
    printf("After remove, countainEdge result is: 0 == %d\n", countainEdge2);

    //Test remove node
    graph_remove_node(graph,3);
    if(find_node(graph,3)==NULL){
        printf("After remove, node3 is NULL\n");
    }else{
        printf("After remove, node3 is not NULL\n");
    }
    
    //Test remove methods;
    printf("After remove, total nodes: 3==%d\n", graph_num_nodes(graph));
    printf("After remove, total edges: 3==%d\n", graph_num_edges(graph));
    free_graph(graph);

    return 0;
}
