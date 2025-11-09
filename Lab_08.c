/*Write a program to implement Kruskal's Algorithm in order to find the minimum Spanning Tree of a
 connected weighted and undirected graph.*/
 #include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Set {
    int parent;
};

int find(struct Set sets[], int i) {
    if (sets[i].parent != i)
        sets[i].parent = find(sets, sets[i].parent);
    return sets[i].parent;
}

void Union(struct Set sets[], int a, int b) {
    int x = find(sets, a);
    int y = find(sets, b);
    sets[x].parent = y;
}

int cmp(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main() {
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, E, sizeof(edges[0]), cmp);

    struct Set sets[V];
    for (int i = 0; i < V; i++) sets[i].parent = i;

    int cost = 0, count = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        int a = find(sets, edges[i].u);
        int b = find(sets, edges[i].v);
        if (a != b) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            Union(sets, a, b);
            count++;
        }
    }
    printf("Minimum Cost = %d\n", cost);
    return 0;
}
