#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef cplusplus
extern "C" 
{
#endif

// Data types
typedef struct _Node {
    int data;
    struct _Node * next;
} Node;

typedef struct _Queue {
    struct _Node * head;
    struct _Node * tail;
} Queue;

// Prototypes
Queue * initQueue();
Node * makeNode(int data);
void enqueue(Queue * q, int data);
int dequeue(Queue * q);
void freeQueue(Queue * q);

#ifdef cplusplus
}
#endif

#endif