class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>freq;
        long long pairs=0;
        long long ans=0;
        int st=0;
        for(int end=0; end<n ; end++){
            pairs+=freq[nums[end]];
            freq[nums[end]]++;
            while(pairs>=k){
                ans+= n-end;
                freq[nums[st]]--;
                pairs-=freq[nums[st]];
                st++;
            }
        }
        return ans;
    }
};