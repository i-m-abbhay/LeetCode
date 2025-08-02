class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return f(0,0,cols-1, grid, dp);
    }
    int f(int ri, int rj1, int rj2, vector<vector<int>>&grid, vector<vector<vector<int>>> &dp){
        if(rj1<0 || rj2 < 0 || rj1 >= grid[0].size() || rj2>=grid[0].size()){
            return -1e8;
        }
        if(ri==grid.size()-1) {
            return (rj2 == rj1) ?  grid[ri][rj1]: grid[ri][rj1] + grid[ri][rj2];
        }
        if(dp[ri][rj1][rj2]!=-1) return dp[ri][rj1][rj2];
        int maxi = 0;
        for(int i = -1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if (rj1==rj2) maxi = max(maxi , grid[ri][rj1]+f(ri+1, rj1+i, rj2+j, grid, dp));
                else maxi = max(maxi , grid[ri][rj1]+ grid[ri][rj2]+f(ri+1, rj1+i, rj2+j, grid, dp));
            }
        }
        return dp[ri][rj1][rj2] = maxi;
    }
};