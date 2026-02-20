/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Allocate initial space for result
    int** res = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize - 2; i++) {
        // Early exit
        if (nums[i] > 0) break;
        
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int l = i + 1, r = numsSize - 1;
        int target = -nums[i];
        
        while (l < r) {
            int s = nums[l] + nums[r];
            
            if (s == target) {
                // Allocate space for triplet
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                l++;
                r--;
                
                // Skip duplicates for l and r
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
                
            } else if (s < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    
    return res;
}
