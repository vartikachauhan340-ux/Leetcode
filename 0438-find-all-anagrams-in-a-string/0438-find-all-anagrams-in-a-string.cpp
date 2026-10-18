class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int  n=s.size();
        int m = p.size();
        if(m==0 || m> n){
            return ans;
        }
        vector<int> pfreq(26, 0);
        vector<int> sfreq(26, 0);
        for(int i=0; i<m; i++){
            pfreq[p[i] - 'a']++;
            sfreq[s[i] - 'a']++;
        }
        for(int i=0; i<= n-m; i++){
            if(pfreq == sfreq){
                ans.push_back(i);
            }
            if(i <n-m){
                sfreq[s[i] - 'a']--;
                sfreq[s[i+m] - 'a']++;
            }
        }
        return ans;
        
    }
};