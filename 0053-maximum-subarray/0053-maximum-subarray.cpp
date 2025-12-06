class Solution {
private:
    //*******BRUTE FORCE*****
    // int sum(vector<int> &nums, int s, int e){
    //     int sum = 0;
    //     for(int i = s; i<=e; i++){
    //         sum+=nums[i];
    //     }
    //     return sum;
    // }
public:
    int maxSubArray(vector<int>& nums) {
        //****BRUTE FORCE***** O N3
        // int maxSum = INT_MIN;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i; j<nums.size();j++){
        //         maxSum = max(maxSum, sum(nums,i,j));
        //     }
        // }
        // return maxSum;

        //******BETTER******* O N2
        // int maxSum = INT_MIN;
        // for(int i=0;i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j=i; j<nums.size();j++){
        //         sum+=nums[j];
        //         maxSum = max(sum,maxSum);
        //     }
            
        // }
        // return maxSum;

        //*****Optimal (Kadane's Algorithm)*******
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1; i<nums.size();i++){ // simple do not carry forward the sum which hampers next element
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};