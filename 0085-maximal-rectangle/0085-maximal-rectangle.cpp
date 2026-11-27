class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n= heights.size();
        int ans=0;
        for(int i=0; i<=n; i++){
            int curr = (i==n) ? 0: heights[i];
            while(!st.empty() && heights[st.top()] > curr){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                } else{
                    width = i- st.top() -1;
                }
                int area = height*width;
                ans = max(ans, area);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> h(col, 0);
        int ans=0;
        for(int i=0; i< row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                } else{
                    h[j] =0;
                }
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};