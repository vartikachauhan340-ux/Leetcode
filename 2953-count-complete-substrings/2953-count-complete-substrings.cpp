class Solution {
public:
    int countsegment(string s, int k){
        int n= s.size();
        int ans=0;
        for(int distinct=1; distinct<=26; distinct++){
            int len= distinct * k;
            if(len > n){
                break;
            }
            vector<int>cnt (26, 0);
            vector<int>freq(n+1, 0);
            for(int r=0; r<n; r++){
                int c= s[r]-'a';
                freq[cnt[c]]--;
                cnt[c]++;
                freq[cnt[c]]++;
                if(r >= len){
                    int leftchar= s[r-len] - 'a';
                    freq[cnt[leftchar]]--;
                    cnt[leftchar]--;
                    freq[cnt[leftchar]]++;
                }
                if(r >= len-1 && freq[k] == distinct){
                    ans++;
                }
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int n= word.size();
        int ans=0;
        int st=0;
        for(int i=1; i<=n; i++){
            if(i == n || abs(word[i] - word[i-1]) > 2){
                string s= word.substr(st, i-st);
                ans+= countsegment(s, k);
                st = i;
            }
        }
        return ans;
    }
};