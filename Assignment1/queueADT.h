// Samantha Souder, John Stockton
// CS-451
// Dr. Kanchi
// Summer 2022

//Create API for queue ADT
//    Main program using queue will not see implementation
//    Type of item in queue is determinded via include statement

//typedef char dataType;
//typedef double dataType;

//Defines the 'objects' (structs) that the queue will contain
typedef struct node {
    struct node *previous;
    int data;
} nodeType;

//Defines the 'object' (struct) that represents the queue itself
typedef struct queueHeader {
    struct node *head;
    struct node *tail;
} queueType;

//Header functions for the queue.c file to implement
//See queue.c for further documentation
queueType* create();
int isEmpty(queueType *);
queueType* enqueue(int, queueType*);
int dequeue(queueType*);
queueType* destroy(queueType**);