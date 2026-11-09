class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int st=0;
        int mx=0;
        for(int end=0; end<nums.size(); end++){
            mp[nums[end]]++;
            while(mp[nums[end]]> k){
                mp[nums[st]]--;
                st++;
            }
            mx= max(mx, end-st+1);
        }
        return mx;
    }
};