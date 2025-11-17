#include <stdio.h>
#include "MUCSGraph.h"
#include "DFS.h"

// Helper function for PrintDFS
// Explores vertices adjacent to a given vertex
void visitDFS(Vertex * graph, Vertex * vertex, int * time) {
    vertex->color = GRAY;
    vertex->d = ++(*time);

    PAdjacency list = vertex->list;
    while (list && list->pEdge) {
        Vertex * adjV = NULL;

        if (list->pEdge->to == vertex->number) {
            adjV = graph + list->pEdge->from - 1;
        } else {
            adjV = graph + list->pEdge->to - 1;
        }

        if (adjV->color == WHITE) {
            adjV->predecessor = vertex->number - 1;
            visitDFS(graph, adjV, time);
        }

        list = list->next;
    }

    vertex->color = BLACK;
    vertex->f = ++(*time);
    printf("%d(%d) ", vertex->number, vertex->f);
}

// Prints the order of depth first search and the time each vertex took to be finished
void PrintDFS(Vertex * V, int countV, Edge * E, int countE) {
    printf("DFS:\n");

    for (int i = 0; i < countV; i++) {
        V[i].color = WHITE;
    }

    int time = 0;

    for (int i = 0; i < countV; i++) {
        if (V[i].color == WHITE) {
            visitDFS(V, V + i, &time);
        }
    }
    
    printf("\n");
}