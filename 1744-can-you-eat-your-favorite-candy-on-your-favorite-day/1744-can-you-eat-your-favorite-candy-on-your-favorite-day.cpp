class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n= candiesCount.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]= prefix[i] + candiesCount[i];
        }
        vector<bool> ans;
        for(auto& q: queries){
            int type= q[0];
            long long day= q[1];
            long long cap= q[2];
            long long minEat= day+1;
            long long maxEat= (day+1) * cap;
            if(maxEat > prefix[type] && minEat<= prefix[type+1]){
                ans.push_back(true);
            } else{
                ans.push_back(false);
            }
        }
        return ans; 
    }
};