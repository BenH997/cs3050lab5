#include "Queue.h"
#include <stdlib.h>

// Initialize new queue
Queue * initQueue() {
    Queue * q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Creates a new node
Node * makeNode(int data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Queues an item
void enqueue(Queue * q, int data) {
    if (!q) return;

    if (!q->tail && !q->head) {
        q->tail = makeNode(data);
        q->head = q->tail;
        return;
    }

    q->tail->next = makeNode(data);
    q->tail = q->tail->next;
    return;
}

// Removes an item from a queue
int dequeue(Queue * q) {
    if (!q || !q->head) return 0;

    Node * node = q->head;
    int data = node->data;
    q->head = node->next;

    if (!q->head) {
        q->tail = NULL;
    }

    free(node);

    return data;
}

// Frees a queue
void freeQueue(Queue * q) {
    if (!q) return;

    while (q->head) {
        Node * temp = q->head->next;
        free(q->head);
        q->head = temp;
    }
    free(q);
}