class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fq =1;
        int num = nums[0];
        for(int i=1;i<nums.size();i++){
            if(num == nums[i]) fq++;
            else if (fq == 0){
                num = nums[i];
                fq++;
            }
            else{
                fq--;
            }
        }
        return num;
    }
};