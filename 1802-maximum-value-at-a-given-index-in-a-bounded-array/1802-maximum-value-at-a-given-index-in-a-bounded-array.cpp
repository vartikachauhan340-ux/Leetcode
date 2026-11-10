class Solution {
public:
    long long getSum(long long peak, long long cnt){
        if(peak>= cnt){
            return cnt*(2*peak - cnt+1)/2;
        }
        return peak*(peak+1)/2 + (cnt-peak);
    }
    int maxValue(int n, int index, int maxSum) {
        long long low=1;
        long long high= maxSum;
        long long ans=1;
        while(low<= high){
            long long mid= low+(high-low)/2;
            long long left= getSum(mid-1, index);
            long long right= getSum(mid-1, n-index-1);
            long long total= left + mid + right;
            if(total<= maxSum){
                ans= mid;
                low= mid+1;
            } else{
                high= mid-1;
            }
        }
        return ans;
    }
};