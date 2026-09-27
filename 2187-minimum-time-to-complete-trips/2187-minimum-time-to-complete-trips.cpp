class Solution {
public:
    bool isValid(vector<int>& time, int totalTrips, long long mid){
        long long trip=0;
        for(int i=0; i<time.size(); i++){
            trip+=mid/time[i];
        }
        return trip>= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1; 
        long long min= *min_element(time.begin(), time.end());
        long long high= totalTrips*min;
        while(low<=high){
            long long mid= low+(high-low)/2;
            if (isValid(time, totalTrips, mid)){
                high= mid-1;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};