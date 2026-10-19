class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0, start=0;
        unordered_map<int, int>map;
        for(int end=0; end<fruits.size(); end++){
            map[fruits[end]]++;
            while(map.size() > 2){
                map[fruits[start]]--;
                if(map[fruits[start]] == 0){
                    map.erase(fruits[start]);
                }
                start++;
            }
            ans = max(ans, end - start +1);
        }
        return ans;
    }
};