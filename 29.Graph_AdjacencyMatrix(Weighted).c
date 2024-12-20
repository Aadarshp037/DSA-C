// Graph implementation using adjacency matrix for weighted graph

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
            if (i == j)
                g->adjMatrix[i][j] = 0;  
            else
                g->adjMatrix[i][j] = 0;  
        }
    }
}

void addEdge(Graph* g, int startVertex, int endVertex, int weight) {
    g->adjMatrix[startVertex][endVertex] = weight;
    g->adjMatrix[endVertex][startVertex] = weight;  
}

void removeEdge(Graph* g, int startVertex, int endVertex) {
    g->adjMatrix[startVertex][endVertex] = 0;
    g->adjMatrix[endVertex][startVertex] = 0;  
}
void printGraph(Graph* g) {
    printf("Adjacency Matrix (Weighted):\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 0 && i != j)  
                printf("0\t");
            else
                printf("%d\t", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, start, end, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (start end weight): ");
        scanf("%d %d %d", &start, &end, &weight);
        addEdge(&g, start, end, weight);
    }

    printf("\nGraph Representation:\n");
    printGraph(&g);

    return 0;
}
