class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        int freq = nums.size()/3;
        vector<int> ans;
        for(auto el: mp){
            if(el.second>freq) ans.push_back(el.first);
        }
        return ans;
    }
};