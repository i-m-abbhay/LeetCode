class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vpii;
        for(int i= 0; i<nums.size();i++){
            vpii.push_back({nums[i], i});
        }
        sort(vpii.begin(), vpii.end());
        int start = 0, end = vpii.size()-1;
        while(start<end){
            if(vpii[start].first+vpii[end].first == target){
                return {vpii[start].second, vpii[end].second};
            }
            else if(vpii[start].first+vpii[end].first > target){
                end--;
            }
            else{
                start++;
            }
        }
        return {};
    }
};