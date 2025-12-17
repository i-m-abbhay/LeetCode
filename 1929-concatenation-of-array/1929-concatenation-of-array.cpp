class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n*2);
        for(int i = 0; i<n*2; i++){
            if (i<n)
                ans[i]=nums[i];
            else{
                ans[i]=nums[i-n];
            }
        }
        return ans;
    }
};