class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int x= left; x<= right; x++){
            bool found= false;
            for(auto &range : ranges){
                if(x >= range[0] && x<= range[1]){
                    found = true;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};