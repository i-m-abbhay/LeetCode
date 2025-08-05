class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum_num = 0;
      
        for(auto i: nums){
            sum_num += i;
        }
        if(sum_num%2!=0) return false;
        int target = sum_num/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        
        return subsetSumToK(nums.size()-1, target, nums, dp);
    }
    bool subsetSumToK(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(ind==0){
            return target == nums[ind] ? true : false;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = subsetSumToK(ind - 1, target, nums, dp);
        bool take = false;
        if (target >= nums[ind]) {
            take = subsetSumToK(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take || notTake;
    }
};