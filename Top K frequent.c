/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OCC 0
#define EMP -1
struct elem{
    int key;
    int value;
    int status; //O, -1 = Occ, Emp
};
struct hashMap{
    struct elem * array; //Similar to stack/queue of array
    int size;
};

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int probeFunc1(int key, int i, int SIZE) {
    return ((key + i) % SIZE + SIZE) % SIZE;
}

struct hashMap * hashMapInit(int size){
    struct hashMap * newMap = malloc(sizeof(struct hashMap));
    newMap->size = size;
    newMap->array = malloc(sizeof(struct elem)*size);
    for(int i=0;i<size;i++){
        newMap->array[i].status = EMP;
        newMap->array[i].value = 0;
        newMap->array[i].key = 0;
    }
    return newMap;
}

int searchHashMap(struct hashMap * HT, int key){
    int i=-1;
    int probe;
    do{
        i++; probe=probeFunc1(key, i, HT->size);
    } while((i<HT->size && HT->array[probe].status!=OCC) || (HT->array[probe].key != key && HT->array[probe].status!=EMP));
    if(i>=HT->size || HT->array[probe].status == EMP){
        return -1;
    }
    return probe;
}

int insertHashMap(struct hashMap * HT, int key, int value){
    int i=-1;
    int probe;
    do{i++; probe=probeFunc1(key, i, HT->size);
    }while(i<HT->size && HT->array[probe].status == OCC);
    if(i>=HT->size){
        return -1;
    }
    HT->array[probe].status = OCC;
    HT->array[probe].key = key;
    HT->array[probe].value = value;
    return probe;
}



void heapify(int * array, int * follow, int curr, int size){
    int m = curr;
    int lft = 2*curr+1;
    int rgt = 2*curr+2;
    if(lft<=size && array[lft]>array[m]){m = lft;}
    if(rgt<=size && array[rgt]>array[m]){m = rgt;}
    if(curr!=m){
        swap(&array[curr], &array[m]);
        swap(&follow[curr], &follow[m]);
        heapify(array, follow, m, size);
    }
}

void buildHeap(int * array, int * follow, int n){
    for(int i = (n-1)/2; i>=0; i--){
        heapify(array, follow, i, n-1);
    }
}




int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
        struct hashMap * ht = hashMapInit(numsSize);
    for(int i = 0; i<numsSize; i++){
        int key = nums[i];
        int searchIdx = searchHashMap(ht, key);
        if(searchIdx == -1){
            insertHashMap(ht, key, 1);
        }
        else{
            ht->array[searchIdx].value++;
        }
    }

    int tmpSize = 0;
    for(int i=0; i<numsSize; i++){
        if(ht->array[i].status == OCC){
            tmpSize++;
        }
    }

    int tmp_keys[tmpSize];
    int tmp_values[tmpSize];
    int idx = 0;
    for(int i=0; i<numsSize; i++){
        if(ht->array[i].status == OCC){
            tmp_keys[idx] = ht->array[i].key;
            tmp_values[idx] = ht->array[i].value;
            idx++;
        }
    }
    buildHeap(tmp_values, tmp_keys, tmpSize);
    int size = tmpSize-1;
    int * output = malloc(sizeof(int)*k);
    for(int i = 0; i<k; i++){
        output[i] = tmp_keys[0];
        swap(&tmp_values[0], &tmp_values[size]);
        swap(&tmp_keys[0], &tmp_keys[size]);
        size--;
        heapify(tmp_values, tmp_keys, 0, size);
    }
    free(ht->array); 
    free(ht); 
    return output;
}
