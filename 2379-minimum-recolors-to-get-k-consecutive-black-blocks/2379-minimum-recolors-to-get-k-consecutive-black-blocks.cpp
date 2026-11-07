class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int st=0;
        int count=0;
        int ans= INT_MAX;
        for(int end=0; end<blocks.size(); end++){
            if(blocks[end] == 'W'){
                count++;
            }
            if(end-st+1 == k){
                ans= min(ans, count);
                if(blocks[st] == 'W'){
                    count--;
                }
                st++;
            }
        }
        return ans;
    }
};