class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0, maxnum=INT_MIN;
        for(int val:nums){
            currsum+=val;
            maxnum=max(currsum,maxnum);
            if(currsum<0){
                currsum = 0;
            }
        }
    return maxnum;   
    }
};