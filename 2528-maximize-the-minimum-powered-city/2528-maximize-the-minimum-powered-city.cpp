class Solution {
public:
    bool check(vector<long long>& power, int r, int k, long long target){
        int n= power.size();
        vector<long long> diff(n+1, 0);
        int added=0;
        for(int i=0; i<n; i++){
            added+= diff[i];
            long long current= power[i]+added;
            if(current<target){
                long long need= target- current;
                k-=need;
                if(k<0){
                    return false;
                }
                added+=need;
                int pos= min(n-1, i+r);
                int end= min(n, pos+r+1);
                diff[end]-= need;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n= stations.size();
        vector<long long>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]= prefix[i] + stations[i];
        }
        vector<long long> power(n);
        for(int i=0; i<n; i++){
            int left= max(0, i-r);
            int right= min(n-1, i+r);
            power[i]= prefix[right+1]- prefix[left];
        }
        long long low=0; 
        long long high= prefix[n] + k;
        long long ans=0;
        while(low<= high){
            long long mid= low+(high-low)/2;
            if(check(power, r, k, mid)){
                ans=mid;
                low= mid+1;
            } else{
                high= mid-1;
            }
        }
        return ans;
    }
};