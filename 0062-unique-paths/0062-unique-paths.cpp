class Solution {
private:
    int move(int row, int col, int m, int n, vector<vector<int>>& dp){
        if(row==m-1 && col == n-1) return 1;
        if(row>=m || col >= n) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int right = move(row, col+1, m, n, dp);
        int down = move(row+1, col, m, n, dp);
        return dp[row][col] = right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return move(0, 0, m, n, dp);
    }
};