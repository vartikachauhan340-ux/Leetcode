class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int st=0;
        int diff=0;
        int mx=0;
        for(int end=0; end<s.size(); end++){
            diff+=  abs(s[end]- t[end]);
            while(diff > maxCost){
                diff-= abs(s[st]-t[st]);
                st++;
            }
            mx= max(mx, end-st+1);
        }
        return mx;
    }
};