int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;

    int maxKadane = nums[0], currMax = 0;
    int minKadane = nums[0], currMin = 0;

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        maxKadane = (currMax > maxKadane) ? currMax : maxKadane;

        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        minKadane = (currMin < minKadane) ? currMin : minKadane;
    }

    if (maxKadane < 0)
        return maxKadane;

    return (maxKadane > totalSum - minKadane)
           ? maxKadane
           : totalSum - minKadane;
}
