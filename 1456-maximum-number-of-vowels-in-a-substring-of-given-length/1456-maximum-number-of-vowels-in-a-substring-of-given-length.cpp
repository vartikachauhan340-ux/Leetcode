class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int start=0, count=0;
        int max_value = 0;
        for(int end=0; end < s.size(); end++){
            if(isVowel(s[end])){
                count+=1;
                
            }
            if(end >= k-1){
                max_value = max(max_value, count);
                if(isVowel(s[start])){
                    count-=1;
                }
                start++;
            }
        }
        return max_value;
    }
};