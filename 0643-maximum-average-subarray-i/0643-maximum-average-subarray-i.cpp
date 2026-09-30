class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start=0, end=0, sum=0;
        double max_avg= -1e9;
        for(int end=0; end < nums.size();end++){
            sum+= nums[end];
            if(end>=k-1){
                max_avg= max(max_avg, (double)sum/k);
                sum-= nums[start];
                start+=1;
            }
        }
        return max_avg;
    }
};