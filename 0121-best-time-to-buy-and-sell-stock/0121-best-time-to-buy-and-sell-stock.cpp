class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int MP=0;
        int BB = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(BB< prices[i]){
                MP= max(MP, prices[i]-BB);
            }
            BB= min(BB, prices[i]);
        }
        return MP;
           
    }
};