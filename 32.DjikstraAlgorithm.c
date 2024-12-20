// Djikstra Algorithm in graph of adjacency List

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createNode(src, weight); 
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void djikstra(struct Graph* graph, int startVertex) {
    int* dist = (int*)malloc(graph->numVertices * sizeof(int));
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        
        int min = INT_MAX, u;
        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = true;

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            if (!visited[temp->vertex] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[temp->vertex]) {
                dist[temp->vertex] = dist[u] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("\nShortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        if (dist[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }

    free(dist);
    free(visited);
}

int main() {
    struct Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 2, 3, 9);
    addEdge(graph, 3, 4, 4);
    
    djikstra(graph, 0);
    
    free(graph->adjLists);
    free(graph);
    
    return 0;
}