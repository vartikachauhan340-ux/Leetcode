class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> events;
        for(auto flower: flowers){
            events[flower[0]]++;
            events[flower[1] +1]--;
        }
        vector<pair<int, int>> queries;
        for(int i=0; i<people.size(); i++){
            queries.push_back({people[i], i});
        }
        sort(queries.begin(), queries.end());
        vector<int> ans(people.size());
        int bloomed=0;
        auto it= events.begin();
        for(auto q: queries){
            int time= q.first;
            int idx= q.second;

            while(it != events.end() && it-> first <= time){
                bloomed+= it->second;
                it++;
            }
            ans[idx]= bloomed;
        }
        return ans;
    }
};