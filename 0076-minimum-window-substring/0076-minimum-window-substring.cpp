class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        vector <int> freq(128, 0);
        for(char c : t){
            freq[c]++;
        }
        int st=0;
        int left=0;
        int min_len= INT_MAX;
        int req = t.size();
        for(int end=0; end< s.size(); end++){
            char c = s[end];
            if(freq[c] > 0){
                req--;
            }
            freq[c]--;

            while(req == 0){
                int WS = end - left +1;
                if(WS < min_len){
                    min_len = WS;
                    st = left;
                }
                char leftChar= s[left];
                freq[leftChar]++;
                if(freq[leftChar] > 0){
                    req++;
                }
                left++;
            }
        }
        if(min_len == INT_MAX){
            return "";
        }
        return s.substr(st, min_len);
    }
};