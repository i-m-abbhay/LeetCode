class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int start = 0, end = cols*rows - 1;
        while(start<=end){
            int mid = start + (end - start) /2;
            if(matrix[mid/cols][mid%cols]==target) return true;
            else if(matrix[mid/cols][mid%cols]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
};