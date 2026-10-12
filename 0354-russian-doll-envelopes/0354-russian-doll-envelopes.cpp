class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            if(a[0] == b[0]){
                return a[1]> b[1];
            }
            return a[0]<b[0];
        });
        vector<int> lis;
        for(int i=0; i< envelopes.size();i++){
            int h= envelopes[i][1];
            int low=0, high = lis.size();
            while(low<high){
                int mid=low+(high-low)/2;
                if(lis[mid] < h){
                    low= mid+1;
                } else{
                    high = mid;
                }
            }
            if(low==lis.size()){
                lis.push_back(h);
            } else{
                lis[low]=h;
            }
        }
        return lis.size();
        
    }
};