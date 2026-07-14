class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x: nums){
            if(s.count(x)){
                return 1;
            }
            s.insert(x);
        }
        return 0;
    }
};