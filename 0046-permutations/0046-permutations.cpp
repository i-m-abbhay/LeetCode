class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        permutation(result, nums, used, current);
        return result;
    }
private:
    void permutation( vector<vector<int>> &result, vector<int> &nums, vector<bool> &used, vector<int>&current){
        if(current.size()==nums.size()) result.push_back(current);
        for(int i = 0; i<nums.size();i++){
            if (used[i]) continue;
            current.push_back(nums[i]);
            used[i] = true;
            permutation(result, nums,used, current);
            current.pop_back();
            used[i] = false;
        }
    }
};