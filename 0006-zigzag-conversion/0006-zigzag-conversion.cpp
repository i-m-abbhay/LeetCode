class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        vector<vector<char>> mat(numRows, vector<char>(s.size(), ' '));
        int i = 0, j = 0;
        bool down = true;   // moving straight down the column
        bool diag = false;  // moving up-right

        mat[i][j] = s[0];

        for (int k = 1; k < (int)s.size(); ++k) {
            if (down) {
                if (i < numRows - 1) {
                    i++;               
                } else {
                    // hit bottom
                    down = false; 
                    diag = true;
                    i--; j++;           
                }
            } else { // diag
                if (i > 0) {
                    i--; j++;           
                } else {
                    // hit top
                    down = true; 
                    diag = false;
                    i++;                
                }
            }
            mat[i][j] = s[k];
        }

        string result;
        result.reserve(s.size());
        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < (int)mat[r].size(); ++c) {
                if (mat[r][c] != ' ') result.push_back(mat[r][c]);
            }
        }
        return result;
    }
};
