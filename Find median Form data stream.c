#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// -------- Heap Utilities --------
typedef struct {
    int *data;
    int size;
    int capacity;
    int isMinHeap; // 1 for min-heap, 0 for max-heap
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

int compare(Heap* h, int a, int b) {
    return h->isMinHeap ? (a > b) : (a < b);
}

void heapifyUp(Heap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (compare(h, h->data[parent], h->data[idx])) {
            swap(&h->data[parent], &h->data[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(Heap* h, int idx) {
    while (1) {
        int left = 2 * idx + 1, right = 2 * idx + 2, best = idx;
        if (left < h->size && compare(h, h->data[best], h->data[left])) best = left;
        if (right < h->size && compare(h, h->data[best], h->data[right])) best = right;
        if (best != idx) {
            swap(&h->data[best], &h->data[idx]);
            idx = best;
        } else break;
    }
}

void pushHeap(Heap* h, int val) {
    h->data[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int popHeap(Heap* h) {
    int root = h->data[0];
    h->data[0] = h->data[--h->size];
    heapifyDown(h, 0);
    return root;
}

int topHeap(Heap* h) {
    return h->data[0];
}

// -------- MedianFinder --------
typedef struct {
    Heap* maxHeap; // lower half
    Heap* minHeap; // upper half
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createHeap(50000, 0); // max-heap
    mf->minHeap = createHeap(50000, 1); // min-heap
    return mf;
}

void medianFinderAddNum(MedianFinder* mf, int num) {
    pushHeap(mf->maxHeap, num);
    pushHeap(mf->minHeap, popHeap(mf->maxHeap));
    if (mf->minHeap->size > mf->maxHeap->size) {
        pushHeap(mf->maxHeap, popHeap(mf->minHeap));
    }
}

double medianFinderFindMedian(MedianFinder* mf) {
    if (mf->maxHeap->size > mf->minHeap->size) {
        return (double)topHeap(mf->maxHeap);
    } else {
        return ((double)topHeap(mf->maxHeap) + (double)topHeap(mf->minHeap)) / 2.0;
    }
}

void medianFinderFree(MedianFinder* mf) {
    free(mf->maxHeap->data);
    free(mf->minHeap->data);
    free(mf->maxHeap);
    free(mf->minHeap);
    free(mf);
}
