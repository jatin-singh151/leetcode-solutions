#include <stdlib.h>

int merge_and_count(int arr[], int t[], int l, int m, int r) {
    int count = 0;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if ((long long)arr[i] > 2 * (long long)arr[j]) {
            // Because the left subarray (arr[l...m]) is sorted,
            // all remaining elements from 'i' to 'm' will also
            // be greater than 2 * arr[j].
            count += (m - i + 1);
            j++;
        } else {
            i++;
        }
    }

    // Second pass: Merge the two sorted subarrays
    i = l;
    j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            t[k++] = arr[i++];
        } else {
            t[k++] = arr[j++];
        }
    }

    while (i <= m) {
        t[k++] = arr[i++];
    }

    while (j <= r) {
        t[k++] = arr[j++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = t[i];
    }

    return count;
}

int mergeSort_and_count(int arr[], int t[], int l, int r) {
    if (l >= r) {
        return 0;
    }

    int count = 0;
    int m = l + (r - l) / 2;

    // Count reverse pairs in the left and right halves recursively
    count += mergeSort_and_count(arr, t, l, m);
    count += mergeSort_and_count(arr, t, m + 1, r);

    // Count reverse pairs that cross the middle boundary and merge
    count += merge_and_count(arr, t, l, m, r);

    return count;
}

int reversePairs(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int result = mergeSort_and_count(nums, temp, 0, numsSize - 1);
    free(temp);
    return result;
}
