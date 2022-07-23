//  Samantha Souder, John Stockton
//  CS-451
//  Dr. Kanchi
//  Summer 2022

// This imported file is where the data type for the queue nodes is defined
#include "queueADT.h"

#include <stdio.h>
#include <stdlib.h>

// This function creates a new queue data structure with no elements, 
//   allocating the memory requred. Both the 'head' and 'tail' elements
//   are set to null by default. 
// NOTE: The data type that the nodes contain are defined on lines 13 or
//   14 of queueADT.h in the directory
// Inputs: None
// Outputs: pointer to queueType, the queue that was created
queueType* create() {
    queueType *newStack;
    newStack = (queueType *) malloc( sizeof(queueType) );
    if( !(newStack==NULL) ) {
        // Init head and tail elements to NULL
        newStack -> head = NULL;
        newStack -> tail = NULL;
    }
    return newStack;
}

// This function finds if the passed queue is empty by seing if the 
//   'tail' node is null, if it is, the queue must be empty
// Inputs: pointer to queueType, the queue to be checked for emptiness
// Outputs: int (boolean) 1 if the queue is empty
//                        0 if the queue is NOT empty
int isEmpty( queueType *queue ) {
    if( queue -> head == NULL ) { return 1; }
    return 0;
}

// This function adds a new node to the head of the queue, allocating
//   the memory for each element
// Inputs: dataType, the data of the node to be added
//           (as defined in line 13 or 14 of queueADT.h)
//         queueType, the queue to which we will add the data
// Outputs: pointer to queueType, the updated queue
queueType* enqueue(int data, queueType *queue ) {
    if(queue == NULL) { 
        fprintf(stderr, "ERROR: cannot push to null queue.\n");
        return NULL;
    }
    
    // Create new node
    nodeType *newNode = (nodeType*)malloc(sizeof(nodeType));
    newNode -> data = data;

    // Add node to queue
    if(isEmpty(queue)) {
        newNode -> previous = NULL; // There is no other node to point to
        queue -> head = newNode; // Update the head of the queue
    } else {
        // Point the new node to the old head of the queue
        (queue -> tail) -> previous = newNode;
    }
    queue -> tail = newNode; // Set the 'tail' node

    return queue;
}

// This function gets the head node of the queue, 
//   deleting the node from the queue and deallocating the memory of the node
// Inputs: pointer to queueType, the queue from which head node will be popped
// Outputs: NULL, the node has been deleted
int dequeue(queueType *queue) {
    if(queue==NULL) { 
        fprintf(stderr, "ERROR! cannot dequeue from null queue.\n");
        return -1;
    } else if(isEmpty(queue)) {
        fprintf(stderr, "ERROR! cannot dequeue from empty queue.\n");
        return -1;
    }

    nodeType *dequeuedNode = queue -> head;
    int dequeuedData = dequeuedNode -> data;
    queue -> head = dequeuedNode -> previous; // update the head node to the previous node
    if((queue -> head) == NULL) { 
        // We are popping the only node, set the 'tail' node to NULL
        queue -> tail = NULL; 
    }
    free(dequeuedNode); // deallocate the memory for the popped node

    return dequeuedData;
}

// This function deletes an entire queue data structure with no elements, 
//   deallocating the memory. Each of the nodes are deallocated as well.
// Inputs: pointer to pointer to queueType, the queue to delete
// Outputs: NULL, the queue has been deleted
queueType* destroy( queueType **queue ) {
    nodeType *currNode, *previousNode;

    // Go through and deallocate each node of the queue
    if( !isEmpty(*queue) ) {
        currNode = (*queue) -> head;
        previousNode = currNode -> previous;
        while( previousNode!=NULL ) {
            free( currNode );
            currNode = previousNode;
            previousNode = previousNode -> previous;
        }
        free( currNode );
    }

    // Deallocate memory for the whole queue
    free( *queue );
    return NULL; 
}