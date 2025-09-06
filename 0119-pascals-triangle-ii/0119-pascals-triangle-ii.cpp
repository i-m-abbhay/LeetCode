class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev = {1};
        if (n == 0) return prev;

        for (int i = 1; i <= n; ++i) {
            vector<int> cur(i + 1, 1);          
            for (int j = 1; j < i; ++j) {
                cur[j] = prev[j - 1] + prev[j]; 
            }
            prev.swap(cur);
        }
        return prev;
    }
};
