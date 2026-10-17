class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int st=0;
        int max_len=0;
        for(int end=0; end< s.size(); end++){
            char ch =s[end];
            if(lastIndex[ch]>= st){
                st = lastIndex[ch] +1;
            }
            lastIndex[ch] = end;

            max_len = max(max_len, end - st +1);
        }
        return max_len;
    }
};