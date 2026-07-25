class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        int n= position.size();
        int magnet=1, lastposition= position[0];
        for(int i=1; i<n; i++){
            if(position[i]-lastposition >= mid){
                magnet++;
                lastposition= position[i];
            }
            if(magnet==m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n= position.size();
        sort(position.begin(), position.end());
        int st=1, end= position[n-1]-position[0], ans=-1;
        while(st<=end){
            int mid= st+(end-st)/2;
            if (isPossible(position, m, mid)){
                ans=mid;
                st= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        return ans;
        
    }
};