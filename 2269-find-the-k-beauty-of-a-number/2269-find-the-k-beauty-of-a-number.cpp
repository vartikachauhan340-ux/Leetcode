class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s= to_string(num); 
        int count=0;
        int window=0;
        for(int i=0; i<k; i++){
            window= window * 10 +(s[i] - '0');
        }
        if(window !=0 && num % window == 0){
            count++;
        }
        for(int i=k; i<s.size(); i++){
            window= window % (int)pow(10, k-1) * 10 +(s[i] - '0');
            if(window!= 0 && num% window==0){
                count++;
            }
        }
        return count;
        
    }
};