class Solution {
public:
    
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
    int func(int n, vector<int> &dp){
        if(n==1||n==2) return 1;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = func(n-1, dp) + func(n-2, dp) + func(n-3, dp);
    }
};