// =================== Support Code =================
// Graph.
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they 
//      should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
} graph_t;

typedef struct graph_node{
    int data;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
} graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    if(myGraph==NULL){
        return NULL;
    }
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}

// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
    if(g==NULL){
        return NULL;
    }
    node_t* tempNode = g->nodes->head;
    while(tempNode!=NULL){
        graph_node_t* tempGraphNode = tempNode->data;
        if(tempGraphNode->data == value){
            return tempGraphNode;
        }
        tempNode=tempNode->next;
    }
    return NULL;
}

// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return 0;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    if(g==NULL) return -1;
    if(find_node(g, value) == NULL) return 0;
    int pos;
    for(pos=0 ; pos < dll_size(g->nodes) ; pos++){
         graph_node_t * temp = dll_get(g->nodes,pos);
         if(temp->data==value){
             dll_remove(g->nodes,pos);
             g->numNodes--;
             free(temp);
             return 1;
         }
    }
    return 0;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    if(g ==NULL){
        return -1;
    }
    if(find_node(g,source)==NULL || find_node(g,destination)==NULL){
        return 0;
    }
    graph_node_t * sourceNode = find_node(g,source);
    graph_node_t * desNode = find_node(g,destination);
    dll_push_back(sourceNode->outNeighbors,desNode);
    dll_push_back(desNode->inNeighbors,sourceNode);
    g->numEdges++;
    // The function adds an edge from source to destination but not the other way.
    // Make sure you are not adding the same edge multiple times.
    // Make sure you modify the in and out neighbors appropriatelly. destination will be an out neighbor of source.
    // Source will be an in neighbor of destination.
    return 1;
}
// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destintaion){
    if(g==NULL){
        return -1;
    }
    if(find_node(g,source)==NULL || find_node(g,destintaion)==NULL){
        return 0;
    }
    graph_node_t * sourceNode = find_node(g,source);
//    graph_node_t * desNode = find_node(g,destintaion);
//    int flag = 0;
    dll_t* sources = sourceNode->outNeighbors;
//    dll_t* destinations = desNode->inNeighbors;
    int i;
    for(i=0;i<dll_size(sources);i++){
       graph_node_t * temp = dll_get(sources,i);
       if(temp->data==destintaion){
           return 1;
       }
    }
    // for(i=0;i<dll_size(destinations);i++){
    //    graph_node_t * temp = dll_get(sources,i);
    //    if(temp->data == source && flag==1){
    //        return 1;
    //    }
    // }
    return 0;
    
}
// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    if(g ==NULL){
        return -1;
    }
    if(find_node(g,source)==NULL || find_node(g,destination)==NULL){
        return 0;
    }
    if(contains_edge(g,source,destination)==0){
        return 0;
    }
    graph_node_t * sourceNode = find_node(g,source);
    graph_node_t * desNode = find_node(g,destination);
    dll_t* sources = sourceNode->outNeighbors;
    dll_t* destinations = desNode->inNeighbors;
    int i;
    for(i=0;i<dll_size(sources);i++){
       graph_node_t * temp = dll_get(sources,i);
       if(temp->data==destination){
           dll_remove_2(sources,i);
       }
    }
    for(i=0;i<dll_size(destinations);i++){
        graph_node_t * temp = dll_get(destinations,i);
        if(temp->data==source){
            dll_remove_2(sources,i);
            g->numEdges--;
        }
    }
    return 1;
    
}



// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){
    if(g==NULL || find_node(g,value) ==NULL){
        return NULL;
    }
    graph_node_t * currentNode = find_node(g,value);
    return currentNode->inNeighbors;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    if(g==NULL || find_node(g,value) ==NULL){
        return -1;
    }
    int count;
    graph_node_t * currentNode = find_node(g,value);
    count=dll_size(currentNode->inNeighbors);
    return count;
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    if(g==NULL || find_node(g,value) ==NULL){
        return NULL;
    }
    graph_node_t * currentNode = find_node(g,value);
    return currentNode->outNeighbors;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    if(g==NULL || find_node(g,value) ==NULL){
        return -1;
    }
    int count;
    graph_node_t * currentNode = find_node(g,value);
    count=dll_size(currentNode->outNeighbors);
    return count;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    if(g==NULL){
        return -1;
    }
    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    if(g==NULL){
        return -1;
    }
    return g->numEdges;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){
    if(g==NULL){
        return;
    }
    node_t * currentNode = g->nodes->head;
    
    while(currentNode!=NULL){
        graph_node_t * currentGraphNode = currentNode->data;
        free_dll(currentGraphNode->inNeighbors);
        free_dll(currentGraphNode->outNeighbors);
        free(currentGraphNode);
        currentNode=currentNode->next;
    }
    free_dll(g->nodes);
    free(g);
    
}

#endif
