class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        set<pair<int, int>> st;
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]==0 && !st.count({i,j})){
                    st.insert({i, j});
                    int col = 0, row = 0;
                    while(col<n){
                        if (matrix[i][col]!=0 && col!=j){
                            matrix[i][col]=0;
                            st.insert({i,col});
                        }
                        col++;
                    }
                    while(row<m){
                        if(row!=i && matrix[row][j]!=0 ){
                            matrix[row][j]=0;
                            st.insert({row, j});
                        }
                        row++;
                    }
                }
            }
        }
        return;
    }

};