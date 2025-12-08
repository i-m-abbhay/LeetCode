class Solution {
    int helper(vector<int>&coins, int curr, int amount, vector<vector<int>>&dp){
        if(amount == 0) return 0;
        if(curr==coins.size()) return 1e9;
        if(dp[curr][amount]!=-1) return dp[curr][amount];
        int not_take = helper(coins, curr+1, amount, dp);
        int take = 1e9;
        if(coins[curr]<=amount){
            take = 1+helper(coins, curr, amount-coins[curr], dp);
        }
        return dp[curr][amount] = min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        //there is no uniformity in denominations of coins so greedy approach can not be use here.
        //try out all the combos that makes the amount and return the min.
        int ans = helper(coins, 0, amount, dp);
        return (ans >= 1e9 ? -1:ans);
    }
};