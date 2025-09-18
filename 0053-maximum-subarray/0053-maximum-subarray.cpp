class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int prefixSum = 0;
       int minPrefix = 0;
       int maxSum = INT_MIN;
       for(auto num: nums){
            prefixSum = prefixSum+num;
            int candidate = prefixSum - minPrefix;
            if(candidate>maxSum) maxSum = candidate;
            if(prefixSum<minPrefix) minPrefix = prefixSum;
       }
        return maxSum;
    }
};