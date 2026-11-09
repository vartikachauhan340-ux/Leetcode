class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int st=0;
        int zero=0;
        int mx=0;
        for(int end=0; end<nums.size(); end++){
            if(nums[end]==0){
                zero++;
            }
            while(zero > k){
                if(nums[st]==0){
                    zero--;
                }
                st++;
            }
            mx= max(mx, end-st+1);
        }
        return mx;
    }
};