class Solution {
public:
    bool isValid(vector<int>& candies, long long k, long long mid){
        long long children=0;
        for(int i=0; i<candies.size(); i++){
            children+= candies[i]/mid;
        }
        return children>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high= *max_element(candies.begin(), candies.end());
        while(low<=high){
            long long mid= low+(high-low +1)/2;
            if(isValid(candies, k, mid)){
                low=mid+1;
            } else{
                high = mid-1;
            }
        }
        return high;
    }
};