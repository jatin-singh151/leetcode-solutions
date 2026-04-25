int findPeakElement(int* nums, int numsSize) {
    int m=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>nums[m]){
            m=i;
        }      
        

    }
    return m;
}
