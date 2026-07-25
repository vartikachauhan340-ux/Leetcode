class Solution {
public:
    bool isValid(vector<int>& weights, int days, int mid){
        int n= weights.size();
        int day=1, capacity=0;
        for(int i=0; i<n; i++){
            if(weights[i]> mid){
                return false;
            }
            if(capacity + weights[i]<= mid){
                capacity+= weights[i];

            }
            else{
                day++;
                capacity= weights[i];
            }
        }
        return day>days?false:true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int sum=0, mx=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
            mx= max(mx, weights[i]);
        }
        int st=0, end=sum, ans=-1;
        while(st<=end){
            int mid= st+(end-st)/2;
            if(isValid(weights, days, mid)){
                ans=mid;
                end= mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
        
    }
};