class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int b : batteries){
            sum+= b;
        }
        long long low=0;
        long long high= sum/n;
        while(low < high){
            long long mid= low+(high-low+1)/2;
            long long total=0;
            for(int b: batteries){
                total+= min((long long)b, mid);
            }
            if(total >= n*mid){
                low=mid;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};