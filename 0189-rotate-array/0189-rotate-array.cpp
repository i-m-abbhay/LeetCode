class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return;
        k%=n;
        if(k==0) return;
        auto rev = [&](int l, int r){
            while(l<r) swap(nums[l++], nums[r--]);
        };
        rev(0, n-1);
        rev(0, k-1);
        rev(k, n-1);
    }
};