int searchPivot(int* nums, int size) {
    int low = 0, high = size - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int binarySearch(int* nums, int target, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int idx = searchPivot(nums, numsSize);
    int res = binarySearch(nums, target, 0, idx - 1);
    if (res == -1)
        res = binarySearch(nums, target, idx, numsSize - 1);
    return res;

}
