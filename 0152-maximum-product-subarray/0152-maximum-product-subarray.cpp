class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            if (x < 0) {
                std::swap(currMax, currMin);
            }

            currMax = std::max(x, currMax * x);
            currMin = std::min(x, currMin * x);

            ans = std::max(ans, currMax);
        }

        return ans;
    }
};
