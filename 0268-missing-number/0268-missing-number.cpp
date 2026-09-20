class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int low=0, high=n;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(mid<n && nums[mid]==mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};