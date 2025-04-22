#include<stdio.h>

#include <stdlib.h>

#define MAX 100


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;


void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}


void push(int v) {
    stack[++top] = v;
}


void dfs(int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            dfs(u);
        }
        temp = temp->next;
    }

   
    push(v);
}


int i;
void topologicalSort(int vertices) {
    for ( i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int vertices = 6;

  
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(vertices);

    return 0;
}

