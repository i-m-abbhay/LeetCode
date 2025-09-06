class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return vector<string>{};
        vector<string> res;
        int l = nums[0];
        string range = to_string(l);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i] - 1) {
                range += "->";
                while (i < nums.size() && nums[i - 1] == nums[i] - 1) ++i;
                range += to_string(nums[i - 1]);
                res.push_back(range);
                if (i < nums.size()) range = to_string(nums[i]);
                else range.clear();
            } else {
                res.push_back(range);
                range = to_string(nums[i]);
            }
        }
        if (!range.empty()) res.push_back(range);
        return res;
    }
};
