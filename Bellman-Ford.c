#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, source;
    struct Edge edges[MAX * MAX];
    int dist[MAX], parent[MAX];

    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &source);

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    /* Bellman-Ford relaxation */
    for (int i = 1; i <= V - 1; i++) {
        int changed = 0;

        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                changed = 1;
            }
        }

        if (!changed)
            break;
    }

    /* Check negative cycle */
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    /* Print shortest paths */
    for (int i = 1; i <= V; i++) {
        if (i == source)
            continue;

        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            int path[MAX];
            int count = 0;
            int current = i;

            while (current != -1) {
                path[count++] = current;
                if (current == source)
                    break;
                current = parent[current];
            }

            printf("%d %d ", i, dist[i]);

            for (int j = count - 1; j >= 0; j--) {
                printf("%d", path[j]);

                if (j > 0)
                    printf("->");
            }

            printf("\n");
        }
    }

    return 0;
}
