#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int* ans = (int*)malloc(n * sizeof(int));
    int* st = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && temperatures[i] >= temperatures[st[top]]) {
            top--;
        }
        ans[i] = top != -1 ? st[top] - i : 0;
        st[++top] = i;
    }

    *returnSize = n;
    free(st);
    return ans;
}
