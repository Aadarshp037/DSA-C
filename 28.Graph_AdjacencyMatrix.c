// Graph implementation using adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int startVertex, int endVertex) {
    g->adjMatrix[startVertex][endVertex] = 1;
    g->adjMatrix[endVertex][startVertex] = 1; 
}

void removeEdge(Graph* g, int startVertex, int endVertex) {
    g->adjMatrix[startVertex][endVertex] = 0;
    g->adjMatrix[endVertex][startVertex] = 0; 
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("\nAdjacency Matrix:\n");
    printGraph(&g);

    return 0;
}