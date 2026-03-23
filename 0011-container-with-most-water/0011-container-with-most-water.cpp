class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        we can solve this using two pointer approach
        anytime the water volume of water will be
        water = min(height[l], height[r]) * (r-l)
        we need to maximize the above thing...
        we can be a little greedy by moving the pointer which has the min height cause moving the bigger doesn't make sense cause the width (r-l) is gonna decreased anyway so it makes sense to move the smaller one inward.

        */
        int l = 0, r = height.size()-1, bestArea = 0;
        while(l<r){
            int area = min(height[l], height[r]) * (r-l);
            bestArea = max(area, bestArea);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return bestArea;
    }
};