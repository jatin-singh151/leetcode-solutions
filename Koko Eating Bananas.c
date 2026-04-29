long long findHours(int* piles, int size, int speed) {
    long long totalHours = 0;
    for (int i = 0; i < size; i++) {
        if (piles[i] % speed == 0)
            totalHours += piles[i] / speed;
        else
            totalHours += (piles[i] / speed) + 1;
    }
    return totalHours;
}

int findMax(int* piles, int size) {
    int maxElement = 0;
    for (int i = 0; i < size; i++) {
        if (piles[i] > maxElement)
            maxElement = piles[i];
    }
    return maxElement;
}

int minEatingSpeed(int* piles, int size, int h) {
    int maxPiles = findMax(piles, size);
    int low = 1, high = maxPiles, minSpeed = maxPiles;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long checkHours = findHours(piles, size, mid);
        if (checkHours <= h) {
            minSpeed = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return minSpeed;
}
