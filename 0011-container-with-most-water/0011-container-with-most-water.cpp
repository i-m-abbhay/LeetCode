class Solution {
public:
    int maxArea(vector<int>& height) {
        // *********BRUTE FORCE******** O (N2)
        // int maxWater = INT_MIN;
        // for(int i = 0; i<height.size(); i++){
        //     for(int j=1; j< height.size();j++){
        //         maxWater = max(maxWater, (j - i) * min(height[i], height[j]));
        //     }
        // }
        // return maxWater;
        // ****************OPTIMIZED APPROACH************** O(N)
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int water = (right - left) * min(height[left], height[right]);
            maxWater = max(maxWater, water);

            // Move the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};