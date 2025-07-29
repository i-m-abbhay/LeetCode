class Solution {
public:
    int uniquePaths(int m, int n) {
        
        
        
        //tabulation tc = O(m x n), sc = O(m x n)
        //                               ^ dp array (which can be optimized)
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // for(int i=0; i<m; i++){
        //     for(int j=0;j<n; j++){
        //         if(i==0 && j==0){
        //             dp[i][j] = 1;
        //         }
        //         else{
        //             int up = 0, left = 0;
        //             if(i>0) up = dp[i-1][j];
        //             if(j>0) left = dp[i][j-1];
        //             dp[i][j] = up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        
        //space optimized tabulation // space optimize in 1d dp array
        // tc = O(m x n), sc = O(n)
        //                     ^ 2 dp arrays of size n 
        vector<int> prev(n, 0); 
        for(int i = 0; i<m;i++){
            vector<int> cur(n, 0);
            for(int j = 0; j<n;j++){
                if(i==0 && j==0) cur[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1]; 
                    cur[j] = left+up; 
                }
            }
            prev = cur;
        }
        return prev[n-1];

        // memoization 
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return uniquePaths_Memoization(m-1,n-1, dp);
    }
    int uniquePaths_Memoization(int i, int j, vector<vector<int>> &dp){
        // memoization tc= O(m x n) sc = O((m-1)+(n-1))      + O(m x n) 
        //                               ^ recursion stack     ^ dp array
        if(i==0&&j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = uniquePaths_Memoization(i-1, j, dp);
        int left = uniquePaths_Memoization(i, j-1, dp);
        return dp[i][j] = up+left;
    }
};
