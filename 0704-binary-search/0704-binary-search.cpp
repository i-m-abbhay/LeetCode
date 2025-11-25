class Solution {
public:
    int search(vector<int>& nums, int target) {
       int result = -1;
       int l=0, h = nums.size()-1; // l -> 0, h -> 0
       while(l<=h){
        int half = l + (h-l)/2; // 0
        if(nums[half]==target){
            result = half;
            break;
        }
        if(nums[half]<target){
            l = half+1;
        }
        else{
            h = half - 1;
        }
       } 
       return result;
    }
};