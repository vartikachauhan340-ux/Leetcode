class Solution {
public: int findNumbers(vector<int>&arr){
    int ans = 0;
    for (int i = 0; i<arr.size(); i++){
        int num = arr[i];
        int count = 0;

        if( num ==0)
            count = 1;

        while(num!=0){
            count++;
            num = num/10;
        }
        if( count%2==0)
            ans++;
    }
    return ans;
    }
};