class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left=0;
        int maxf=0;
        int maxi=0;
        for(int right=0; right<s.length(); right++){
            mp[s[right]]++;
            maxf= max(maxf, mp[s[right]]);
            while(right-left+1 - maxf >k){
                mp[s[left]]--;
                left++;
            }
            maxi= max(maxi, right-left+1);
        }
        return maxi;
    }
};