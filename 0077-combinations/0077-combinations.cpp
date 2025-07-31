class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combination( 1,n, k, current, result);
        return result;
    }
    void combination(int start ,int n, int k, vector<int> &current, vector<vector<int> >&result){
        if(k==0) result.push_back(current);
        for(int i = start;i<=n;i++){
                current.push_back(i);
                combination(i + 1, n, k - 1, current, result);
                current.pop_back();
        }
    }
};