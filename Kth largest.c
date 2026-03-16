#include <stdio.h>
#include <stdlib.h>

// Min-heap structure
typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapifyUp(MinHeap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent] > h->data[idx]) {
            swap(&h->data[parent], &h->data[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* h, int idx) {
    while (2 * idx + 1 < h->size) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = left;
        if (right < h->size && h->data[right] < h->data[left]) {
            smallest = right;
        }
        if (h->data[idx] > h->data[smallest]) {
            swap(&h->data[idx], &h->data[smallest]);
            idx = smallest;
        } else break;
    }
}

void pushHeap(MinHeap* h, int val) {
    h->data[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int popHeap(MinHeap* h) {
    int root = h->data[0];
    h->data[0] = h->data[--h->size];
    heapifyDown(h, 0);
    return root;
}

int peekHeap(MinHeap* h) {
    return h->data[0];
}

// KthLargest structure
typedef struct {
    MinHeap* heap;
    int k;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = createHeap(k + numsSize); // enough capacity
    obj->k = k;
    for (int i = 0; i < numsSize; i++) {
        if (obj->heap->size < k) {
            pushHeap(obj->heap, nums[i]);
        } else if (nums[i] > peekHeap(obj->heap)) {
            popHeap(obj->heap);
            pushHeap(obj->heap, nums[i]);
        }
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->heap->size < obj->k) {
        pushHeap(obj->heap, val);
    } else if (val > peekHeap(obj->heap)) {
        popHeap(obj->heap);
        pushHeap(obj->heap, val);
    }
    return peekHeap(obj->heap);
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap->data);
    free(obj->heap);
    free(obj);
}
