class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // ---------- Tabulation Approach ----------
        // TC: O(m * n), SC: O(m * n)

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base Case: First row remains the same
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        // Bottom-up DP: Fill the dp matrix from row 1 to m-1
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = dp[i - 1][j];
                int upleft = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int upright = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, upleft, upright});
            }
        }

        // Minimum value in the last row is the answer
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;


        // ---------- Original Memoization Approach (Commented) ----------
        /*
        // Memoization (Top-Down DP with Recursion)
        // TC: O(m * n), SC: O(m * n) for dp + O(m) recursion stack
        // Without memoization: O(3^m) -> TLE on large inputs

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MAX;

        // Try all starting points in last row
        for (int i = 0; i < n; ++i) {
            ans = min(ans, minFallingPathSum(m - 1, i, matrix, dp));
        }

        return ans;
        */
    }

private:
    // ---------- Memoization Helper Function ----------
    int minFallingPathSum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // Out of bounds -> return large value
        if (j < 0 || j >= matrix[0].size()) {
            return 1e9;
        }

        // Base case: first row
        if (i == 0) return matrix[i][j];

        // Return memoized result
        if (dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + minFallingPathSum(i - 1, j, matrix, dp);
        int upleft = matrix[i][j] + minFallingPathSum(i - 1, j - 1, matrix, dp);
        int upright = matrix[i][j] + minFallingPathSum(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(up, min(upleft, upright));
    }
};
