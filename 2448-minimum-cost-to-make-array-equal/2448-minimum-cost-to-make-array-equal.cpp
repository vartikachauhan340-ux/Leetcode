class Solution {
public:
    long long calculate(vector<int>& nums, vector<int>& cost, int target){
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= 1LL* abs(nums[i] - target) * cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low= *min_element(nums.begin(), nums.end());
        int high= *max_element(nums.begin(), nums.end());
        while(low < high){
            int mid= low+(high-low)/2;
            long long cost1= calculate(nums, cost, mid);
            long long cost2= calculate(nums, cost, mid+1);

            if(cost1 <= cost2){
                high=mid;
            } else{
                low= mid+1;
            }
        }
        return calculate(nums, cost, low);
    }
};