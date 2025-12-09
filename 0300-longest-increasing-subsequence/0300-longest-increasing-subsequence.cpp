class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1; i<nums.size();i++){
            if(nums[i]>tmp.back()){
                tmp.push_back(nums[i]);
            } else {
                int ind  = lower_bound(tmp.begin(), tmp.end(),nums[i]) - tmp.begin();
                tmp[ind] = nums[i];
            }
        }
        return tmp.size();
    }
};