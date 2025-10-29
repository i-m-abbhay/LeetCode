class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // int diff = INT_MAX, sum = -1;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             int tempSum = nums[i]+nums[j]+nums[k];
        //             if(abs(target-tempSum)<diff){
        //                 diff = abs(target-tempSum);
        //                 sum = tempSum;
        //             }
        //         }
        //     }
        // }

        int resultSum = nums[0]+nums[1]+nums[2];
        int minDif = abs(target - resultSum);
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==target) return target;
                if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
                int diffToTarget = abs(sum-target);
                if(diffToTarget<minDif){
                    resultSum = sum;
                    minDif = diffToTarget;
                }
            }
        }
        return resultSum;
    }
};