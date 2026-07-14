class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                ans= nums[i]+nums[j];
                if(ans==target){
                    return {i,j};
                }
            }
        }
    return{};
    }
};