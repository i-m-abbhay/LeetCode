class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return pathHelper(0, 0, m-1, n-1, dp);
    }
    int pathHelper(int currRowInd, int currColInd, int maxRowInd, int maxColInd, vector<vector<int>>& dp){
        if(currRowInd==maxRowInd && currColInd == maxColInd) return 1;
        if (currRowInd>maxRowInd || currColInd > maxColInd) return 0;
        if(dp[currRowInd][currColInd]!=-1) return dp[currRowInd][currColInd];
        int right = pathHelper(currRowInd, currColInd+1, maxRowInd, maxColInd, dp);
        int down = pathHelper(currRowInd+1, currColInd, maxRowInd, maxColInd, dp);
        return dp[currRowInd][currColInd] = right + down;
    }
};