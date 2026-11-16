class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n= nums.size();
        long long ans=0;
        int left=-1;
        int lastmin=-1;
        int lastmax=-1;
        for(int right=0; right<n; right++){
            if(nums[right] < minK || nums[right] > maxK){
                left= right;
            }
            if(nums[right] == minK){
                lastmin= right;
            }
            if(nums[right] == maxK){
                lastmax= right;
            }
            int valid= min(lastmin, lastmax) - left;
            if(valid > 0){
                ans+= valid;
            }
        }
        return ans;
    }
};