class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int> dp;
        return targetSum(nums.size()-1, target, nums, dp);
    }

    int targetSum(int ind, int target, vector<int>& nums, map<pair<int,int>, int>& dp) {
        // Base condition
        if (ind == 0) {
            if (nums[0] == 0 && target == 0) return 2;  // Special case: +0 and -0
            return (target == nums[0] || target == -nums[0]) ? 1 : 0;
        }

        // Check if already computed
        if (dp.count({ind, target})) 
            return dp[{ind, target}];

        // Recursive calls: add or subtract current num
        int add = targetSum(ind - 1, target - nums[ind], nums, dp);
        int subtract = targetSum(ind - 1, target + nums[ind], nums, dp);

        // Memoize and return
        dp[{ind, target}] = add + subtract;
        return dp[{ind, target}];
    }
};
