class Solution {
    int dfs(vector<int>& memo, int rem, vector<int> &coins){
        if(rem == 0) return 0;
        if(rem<0) return -1;
        if(memo[rem]!=-2) return memo[rem];
        int best = INT_MAX;
        for(int coin: coins){
            int sub = dfs(memo, rem-coin, coins);
            if(sub>=0) best = min(best, sub+1);
        }
        memo[rem] = (best == INT_MAX) ? -1: best;
        return memo[rem];
    }
public:
    //dp[x] = minimum number of coins needed to make amount x
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2); //-2 not computer, -1 impossible, >=0 answer
    return dfs(memo, amount, coins);
    }
};