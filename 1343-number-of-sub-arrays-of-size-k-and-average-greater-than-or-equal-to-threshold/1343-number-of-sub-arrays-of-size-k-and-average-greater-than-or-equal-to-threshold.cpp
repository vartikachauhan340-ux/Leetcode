class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start=0, end=0, sum=0, count=0;
        for(int end=0; end<arr.size(); end++){
            sum+=arr[end];
            if(end>=k-1){
                if((double)sum/k >= threshold){
                    count++;
                }
            sum-= arr[start];
            start++;
            }
        }
        return count;
    }
};