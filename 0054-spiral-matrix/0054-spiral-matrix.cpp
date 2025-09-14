class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> spiral;
        if(a.empty() || a[0].empty()) return spiral;
        int m = a.size();
        int n = a[0].size();
        int top = 0, bottom = m-1;
        int left = 0, right = n-1;

        spiral.reserve(m*n);

        while (top <= bottom && left <= right) {
        // left -> right
        for (int c = left; c <= right; ++c) spiral.push_back(a[top][c]);
        ++top;

        // top -> bottom
        for (int r = top; r <= bottom; ++r) spiral.push_back(a[r][right]);
        --right;

        // right -> left
        if (top <= bottom) {
            for (int c = right; c >= left; --c) spiral.push_back(a[bottom][c]);
            --bottom;
        }

        // bottom -> top
        if (left <= right) {
            for (int r = bottom; r >= top; --r) spiral.push_back(a[r][left]);
            ++left;
        }
    }
    return spiral;

    }
};