class Solution {
public:
    double soupServings(int n) {
        if(n>4800) return 1.0;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return soup(n,n, dp);
    }
    double soup(int a, int b, vector<vector<double>>&dp){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        double prob = 0.25 * (soup(a-100, b-0, dp)+soup(a-75, b-25, dp)+soup(a-50, b-50, dp)+soup(a-25, b-75, dp));
        return dp[a][b]=prob;
    }
};