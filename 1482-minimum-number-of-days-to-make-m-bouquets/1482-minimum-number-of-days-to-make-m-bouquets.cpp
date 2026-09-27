class Solution {
public:
    int ispossible(vector<int>& bloomDay, int m, int k, int days){
        int flower=0, bouquet=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<= days){
                flower++;
                if(flower == k){
                    bouquet++;
                    flower=0;
                }
            } else{
                flower=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total_flower= 1LL*m*k;
        if(total_flower > bloomDay.size()){
            return -1;
        }
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high= *max_element(bloomDay.begin(), bloomDay.end());
        while(low<= high){
            int mid=low+(high-low)/2;
            if(ispossible(bloomDay, m, k, mid)){
                high= mid-1;;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};