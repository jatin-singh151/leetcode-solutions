int max(int* nums, int n) {
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > maxi) {
            maxi = nums[i];
        }
    }
    return maxi;
}
int sum(int* nums, int n) {
    long long total= 0;
    for (int i = 0; i < n; i++) {
        total+=nums[i];
        }
        return total;
}
int minSum(int* nums,int n,int mid){
    int number=1;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }
        else{
            number++;
            sum=nums[i];
        }
    }
    return number;

}
int splitArray(int* nums, int numsSize, int k) {
    int n=numsSize;
    int low=max(nums,n);
    long long high=sum(nums,n);
    while(low<=high){
        int mid=(low+high)/2;
        if(minSum(nums,n,mid)>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
    

}
