class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int l = 0; int r = height.size()-1;
        while(l<r){
            int currArea = (r-l)*min(height[l], height[r]);
            maxArea = max(maxArea, currArea);
            if(height[l]<height[r])l++;
            else r--;
        }
        return maxArea;
    }
};