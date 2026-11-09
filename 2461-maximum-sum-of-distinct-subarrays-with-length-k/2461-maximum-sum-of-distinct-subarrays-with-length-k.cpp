class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum=0;
        long long mx=0;
        int st=0;
        for(int end=0; end< nums.size(); end++){
            sum+= nums[end];
            mp[nums[end]]++;
            if(end-st+1 > k){
                sum-= nums[st];
                mp[nums[st]]--;
                if(mp[nums[st]] == 0){
                    mp.erase(nums[st]);
                }
                st++;
            }
            if(end-st+1 ==k && mp.size() ==k){
                mx= max(mx, sum);
            }
        }
        return mx;
    }
};