class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int writeInd = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[writeInd++] = nums[i];
            }
        }
        return writeInd;
    }
};