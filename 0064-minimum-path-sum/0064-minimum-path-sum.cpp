class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int> (n, -1));
        return helper(m-1, n-1, grid, dp);
    }
    int helper(int i, int j, vector<vector<int>> & grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = helper(i-1, j, grid, dp);
        int left = helper(i, j-1, grid, dp);
        up == INT_MAX ? up = INT_MAX: up = grid[i][j] + up;
        left == INT_MAX ? left = INT_MAX: left = grid[i][j] + left;
        return dp[i][j]= min(up, left);
    }
};