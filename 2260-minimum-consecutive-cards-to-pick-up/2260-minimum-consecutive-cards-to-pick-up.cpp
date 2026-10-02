class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int start=0;
        unordered_map<int, int> frequencyMap;
        int min_length= INT_MAX;
        for(int end=0; end < cards.size(); end++){
            int curr= cards[end];
            frequencyMap[curr]++;
            while(frequencyMap[curr] == 2){
                min_length = min(min_length, end-start+1);
                frequencyMap[cards[start]]--;
                start++;
            }
        }
        return min_length == INT_MAX ? -1 : min_length;
    }
};