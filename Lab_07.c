/*Consider the undirected graph G, consisting of n nodes laid out in a 3-by-3 grid: Start searching
 at node 1, and break ties for exploring the next node based on lower numerical order 
 (i.e. add nodes to a queue low to high, add nodes to a stack high to low). 
 (a) In what order are nodes marked as explored by BFS? 
 (b) In what order are nodes marked as explored by DFS?*/
 #include <stdio.h>
#include <stdlib.h>

#define N 9

int adj[N + 1][N + 1];
int visited[N + 1];

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void buildGridGraph() {
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0)
            addEdge(i, i + 1);
        if (i + 3 <= 9)
            addEdge(i, i + 3);
    }
}

void BFS(int start) {
    int queue[100], front = 0, rear = 0;
    int node;
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    printf("\nBFS Traversal Order: ");
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= N; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(int start) {
    int stack[100], top = -1;
    int node;
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    printf("\nDFS Traversal Order: ");
    stack[++top] = start;
    while (top >= 0) {
        node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for (int i = N; i >= 1; i--) {
                if (adj[node][i] && !visited[i])
                    stack[++top] = i;
            }
        }
    }
}

int main() {
    buildGridGraph();
    printf("3x3 Grid Graph Traversal\n");
    printf("=========================\n");
    BFS(1);
    DFS(1);
    printf("\n");
    return 0;
}
