class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()){
            return ans;
        }
        int wordlen= words[0].size();
        int wordcount = words.size();
        unordered_map<string, int>mp;
        for(string word : words){
            mp[word]++;
        }
        for(int i=0; i<wordlen; i++){
            unordered_map<string, int> seen;
            int left=i;
            int count =0;
            for(int right=i; right+wordlen<= s.size() ; right+=wordlen){
                string word = s.substr(right, wordlen);
                if(mp.find(word) == mp.end()){
                    seen.clear();
                    count=0;
                    left= right+wordlen;
                    continue;
                }
                seen[word]++;
                count++;
                while(seen[word] > mp[word]){
                    string leftword= s.substr(left, wordlen);
                    seen[leftword]--;
                    count--;
                    left+=wordlen;
                }
                if(count== wordcount){
                    ans.push_back(left);
                    string leftword= s.substr(left, wordlen);
                    seen[leftword]--;
                    count--;
                    left+= wordlen;
                }
            }
        }
        return ans;
    }
};