class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    int atMost(vector<int>& nums, int goal){
        if(goal< 0){
            return 0;
        }
        int st=0;
        int sum=0;
        int count=0;
        for(int end=0; end<nums.size(); end++){
            sum+= nums[end];
            while(sum > goal){
                sum-= nums[st];
                st++;
            }
            count+= end-st+1;
        }
        return count;
    }
};