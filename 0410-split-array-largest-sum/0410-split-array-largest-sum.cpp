class Solution {
public:
    int isValid(vector<int>& nums, int k, long long mid){
        int split=1;
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i]<=mid){
                sum+= nums[i];
            } else{
                split++;
                sum = nums[i];
            }
        }
        return split<= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=0;
        long long high=0;
        for(int x: nums){
            low= max(low, (long long)x);
            high += x;
        }
        while(low<= high){
            long long mid= low+(high-low)/2;
            if(isValid(nums,k, mid)){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};