#include <limits.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize) 
{
    if(numsSize < 2)
        return 0;

    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] < min)
            min = nums[i];
        if(nums[i] > max)
            max = nums[i];
    }

    if(min == max)
        return 0;

    int gap = (max - min) / (numsSize - 1);
    if((max - min) % (numsSize - 1) != 0)
        gap++;

    int bucketSize = numsSize - 1;

    int *bucketMin = malloc(bucketSize * sizeof(int));
    int *bucketMax = malloc(bucketSize * sizeof(int));
    int *used = calloc(bucketSize, sizeof(int));

    for(int i = 0; i < bucketSize; i++)
    {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == min || nums[i] == max)
            continue;

        int index = (nums[i] - min) / gap;

        if(bucketMin[index] > nums[i])
            bucketMin[index] = nums[i];

        if(bucketMax[index] < nums[i])
            bucketMax[index] = nums[i];

        used[index] = 1;
    }

    int prev = min;
    int maxGap = 0;

    for(int i = 0; i < bucketSize; i++)
    {
        if(!used[i])
            continue;

        if(bucketMin[i] - prev > maxGap)
            maxGap = bucketMin[i] - prev;

        prev = bucketMax[i];
    }

    if(max - prev > maxGap)
        maxGap = max - prev;

    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}
