class Solution {
    int helpClimbing(int n, vector<int>&dp){
        if(n==0) return 1;
        if (n<0) return 0;
        if(dp[n]!=-1)return dp[n];
        //two steps
        int twoSteps = helpClimbing(n-2, dp);
        //one step
        int oneStep = helpClimbing(n-1, dp);
        return dp[n]=twoSteps + oneStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        return helpClimbing(n, dp);
    }
};