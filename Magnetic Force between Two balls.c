int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxDistance(int* position, int size, int m) {
    qsort(position, size, sizeof(int),cmp);
    int minF = 1;
    int maxF = (position[size - 1] - position[0]) / (m - 1);
    while (minF < maxF) {
        int mid = (minF + maxF + 1) / 2;
        int fit = 1;
        int nextFit = position[0] + mid;
        for (int i = 0; i < size; ++i)
            if (position[i] >= nextFit) {
                ++fit;
                if (fit >= m)
                    break;
                nextFit = position[i] + mid;
            }
        if (fit >= m)
            minF = mid;
        else
            maxF = mid - 1;
    }
    return minF;
}
