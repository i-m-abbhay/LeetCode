class Solution {
public:
    int findMin(vector<int>& nums) {
        int h=(int)nums.size()-1, l = 0;

        while(l<h){
            int m = l+(h-l)/2;
            if(nums[m]>nums[h]){
                l=m+1;
            } else {
                h = m;
            }
        }
        return nums[l];
    }
};