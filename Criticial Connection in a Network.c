#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define MAXE 200005

int head[MAXN], to[MAXE], nextEdge[MAXE];
int edgeCount = 0;

int disc[MAXN], low[MAXN], visited[MAXN];
int timeCounter;

int **result;
int resultCount;

/* Add undirected edge */
void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;

    to[edgeCount] = u;
    nextEdge[edgeCount] = head[v];
    head[v] = edgeCount++;
}

/* DFS (Tarjan) */
void dfs(int u, int parentEdge) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int e = head[u]; e != -1; e = nextEdge[e]) {
        int v = to[e];

        if (e == (parentEdge ^ 1)) continue;

        if (!visited[v]) {
            dfs(v, e);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                result[resultCount][0] = u;
                result[resultCount][1] = v;
                resultCount++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

/* LeetCode function */
int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {

    memset(head, -1, sizeof(head));
    memset(visited, 0, sizeof(visited));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));

    edgeCount = 0;
    timeCounter = 0;
    resultCount = 0;

    result = (int **)malloc(connectionsSize * sizeof(int *));
    for (int i = 0; i < connectionsSize; i++)
        result[i] = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        addEdge(connections[i][0], connections[i][1]);
    }

    dfs(0, -1);

    *returnSize = resultCount;
    *returnColumnSizes = (int *)malloc(resultCount * sizeof(int));
    for (int i = 0; i < resultCount; i++)
        (*returnColumnSizes)[i] = 2;

    return result;
}
