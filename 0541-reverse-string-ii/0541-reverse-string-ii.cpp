class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.length(); i+=k*2){
            int st=i, end=min(i+k-1, (int)s.length() -1);
            while(st<end){
                swap(s[st], s[end]);
                st++;
                end--;
                }
        }
        return s;
    }
};