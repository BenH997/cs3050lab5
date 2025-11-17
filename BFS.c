#include <stdio.h>
#include <stdlib.h>
#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"

// Traverses a graph using breadth first search and prints the vertices as they become black along with the distance to the start node
void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{ 
    printf("BFS:\n");

    // Init color and distance from start(d)
    for (int i = 0; i < countV; i++) {
        (V + i)->color = WHITE;
        (V + i)->d = 0;
    }

    Queue * q = initQueue();

    // Mark start vertex as visited and enqueue it
    enqueue(q, s - 1); 
    (V + (s - 1))->color = BLACK;

    printf("%d(%d) ", (V + (s - 1))->number, (V + (s - 1))->d);

    // Queue adjacent nodes
    while (q->head) {
        int current = dequeue(q);
        Vertex * currV = V + current;

        PAdjacency list = currV->list;
        while (list && list->pEdge) {
            Vertex * vertex = NULL;

            if (list->pEdge->to == currV->number) {
                vertex = V + list->pEdge->from - 1;
            } else {
                vertex = V + list->pEdge->to - 1;
            }

            if (vertex->color == WHITE) {
                enqueue(q, vertex->number - 1);
                vertex->color = BLACK;
                vertex->d = currV->d + 1;
                printf("%d(%d) ", vertex->number, vertex->d);
            }

            list = list->next; 
        }
    
    }

    printf("\n");
    freeQueue(q);
}