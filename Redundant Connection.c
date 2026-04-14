/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findParent(int* parent, int i) {
    if (parent[i] == -1) {
        return i;
    }
    return findParent(parent, parent[i]);
}

void unionSets(int* parent, int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 0; i <= edgesSize; ++i) {
        parent[i] = -1;
    }

    for (int i = 0; i < edgesSize; ++i) {
        int x = findParent(parent, edges[i][0]);
        int y = findParent(parent, edges[i][1]);

        if (x == y) {
            // If adding the current edge forms a cycle, it is redundant
            result[0] = edges[i][0];
            result[1] = edges[i][1];
            break;
        }

        // Union the sets represented by x and y
        unionSets(parent, x, y);
    }

    free(parent);
    return result;
}
