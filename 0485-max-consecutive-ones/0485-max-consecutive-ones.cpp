class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt = 0, currcnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currcnt++;
                if(currcnt>maxcnt){
                    maxcnt = currcnt;
                }
            }
            else{
                currcnt = 0;
            }
        }
        return maxcnt;
    }
};