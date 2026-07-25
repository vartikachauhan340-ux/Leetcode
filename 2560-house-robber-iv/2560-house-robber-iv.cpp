class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int mid){
        int count=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n= nums.size();
        int st= *min_element(nums.begin(), nums.end());
        int end= *max_element(nums.begin(), nums.end());
        int ans= end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isPossible(nums, k, mid)){
                ans= mid;
                end= mid-1;
            }
            else{
                st= mid+1;
            }
        }
        return ans;
        
    }
};