class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        vector<int> ans(n,0);
        if(k==0){
            return ans;
        }
        int sum =0;
        if(k > 0){
            for(int i=1; i<=k; i++){
                sum+= code[i%n];
            }
            for(int j=0; j<n; j++){
                ans[j] = sum;
                sum-= code[(j+1)%n];
                sum+= code[(j+k+1)%n];
            }
        } else{
            int m= -k;
            for(int i= n-m; i<n; i++){
                sum+= code[i];
            }
            for(int j=0; j<n; j++){
                ans[j] = sum;
                sum-= code[(j-m+n)%n];
                sum+= code[j];
            }
        }
        return ans;
    }
};