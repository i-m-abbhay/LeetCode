class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int a = 0; a<nums.size();a++){
          if(a&&nums[a]==nums[a-1]) continue;
          for(int b = a+1;b<nums.size();b++){
            if(b>a+1&&nums[b]==nums[b-1]) continue;
            int l = b+1;int r = nums.size()-1;
            while(l<r){
                long long int sum = (long long int)nums[a]+nums[b]+nums[l]+nums[r];
                if(sum > target) r--;
                else if(sum<target) l++;
                else{
                    res.push_back({nums[a],nums[b],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) ++l;
                    while(l<r && nums[r]==nums[r-1]) --r;
                    ++l; --r;
                }
            }
          }
        }
        return res;
    }
};