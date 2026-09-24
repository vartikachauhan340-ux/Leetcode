class Solution {
public:
    bool isValid(vector<int>& piles, int h, int speed){
        long long hours=0;
        for(int i =0; i< piles.size(); i++){
            if(piles[i] % speed ==0){
                hours+= piles[i]/speed;
            } else{
                hours+= (piles[i]/speed)+1;
            }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1, high=0;
        for(int i=0; i<piles.size(); i++){
            high= max(high, piles[i]);
        }
        while(low<=high){
            int mid= low+(high-low)/2;
            if (isValid(piles, h, mid)){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return low;
    }
};