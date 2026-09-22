class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m= grid.size();
        int count=0;
        for(int i=0; i<m; i++){
            int low=0; 
            int high=grid[i].size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(grid[i][mid]<0){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            count+= grid[i].size()-low;
        }
        return count;
    }
};