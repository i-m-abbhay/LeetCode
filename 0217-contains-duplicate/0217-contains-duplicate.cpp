class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unq;
        for(auto num:nums){
            unq.insert(num);
        }
        if (unq.size()!=nums.size()){
            return true;
        }
        return false;
    }
};