class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0; int r = n - 1;
        int maxRight = 0;
        int maxLeft = 0;
        int water = 0;
        while(l<r){
            maxLeft = max(height[l], maxLeft);
            maxRight = max(height[r], maxRight);
            if(maxLeft > maxRight){
                water += maxRight - height[r];
                r--;
            }
            else {
                water += maxLeft - height[l];
                l++;
            }
        }
        return water;
    }
};