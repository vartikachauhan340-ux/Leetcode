class Solution {
public:
    bool isValid(vector<int>& nums, int k, int mid){
        int student=1, pages=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>mid){
                return false;
            }
            if(pages+nums[i]<=mid){
                pages+=nums[i];
            }
            else{
                student++;
                pages=nums[i];
            }
        }
        return student>k ?false:true;

    }
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0, mx=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            mx= max(mx, nums[i]);
        }
        int st=0, end=sum, ans=-1;
        while(st<=end){
            int mid= st+(end-st)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};