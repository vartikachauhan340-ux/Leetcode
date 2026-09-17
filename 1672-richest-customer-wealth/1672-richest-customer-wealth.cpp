class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto& customer: accounts){
            int sum=0;
            for(auto& money:customer){
                sum+=money;
            }
            ans= max(ans, sum);
        }
        return ans;
        
    }
};