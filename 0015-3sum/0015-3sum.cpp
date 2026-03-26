class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i=0;i<size-2;i++){
            if(i>0 && nums[i-1]==nums[i]){continue;}
            int j = i+1;
            int k = size-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    results.push_back({nums[i], nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
                else if(sum<0) j++;
                else k--; 
            }
        }
        return results;
    }
};