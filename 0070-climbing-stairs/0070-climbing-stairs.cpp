class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        if (n<=1) return 1;
        return climbStairs(n, dp);
    }
private:

    int climbStairs(int n, vector<int> &dp) {
        if (n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = climbStairs(n-1, dp) + climbStairs(n-2, dp);
    }
};