class Solution {
    /*
    1
    1  1
    1 2  1
    1 3 3  1
    1 4 6  4  1
    1 5 10 10 5 1
    */
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==1){
            return {{1}};
        }
        if(numRows==2){
            return{{1},{1,1}};
        }
        vector<int> prevRow = {1,1};
        vector<vector<int>>ans{{1}, prevRow};
        generate(ans, prevRow, numRows-2);
        return ans;
    }
    void generate(vector<vector<int>>& ans, vector<int>prevRow, int numRows){
        if(numRows<=0){
            return;
        }
        vector<int>currRow;
        currRow.push_back(1);
        for(int i = 1; i<prevRow.size();i++){
            currRow.push_back(prevRow[i]+prevRow[i-1]);
        }
        currRow.push_back(1);
        ans.push_back(currRow);
        generate(ans, currRow, numRows-1);
    }
};