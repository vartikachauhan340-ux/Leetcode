class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int MW = 0, w, h, area, i=0, j=n-1;
        while(i<j){
            w=j-i;
            h= min(height[i], height[j]);
            area= w*h;
            MW= max(MW, area);
            height[i]<height[j] ? i++: j--;
        }
        return MW;
    }
};