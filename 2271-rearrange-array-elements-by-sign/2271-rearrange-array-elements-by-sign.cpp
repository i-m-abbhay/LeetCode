class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
        Start
        posInd = 0
        negInd = 1
        res = []
        for each el in array
            if el < 0
                res[posInd] = el
                posInd+=2;
            else
                res[negInd] = el
                negInd+=2; 
        */
        int posInd = 0, negInd = 1;
        vector<int> res(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res[posInd] = nums[i];
                posInd+=2;
            }
            else{
                res[negInd] = nums[i];
                negInd+=2;
            }
        }
        return res;
    }
};