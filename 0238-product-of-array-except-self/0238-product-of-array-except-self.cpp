class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        if (n==0) return {};
        if (n==1) return {1};
        vector<int> pre(n), post(n), res(n);
        int p = 1;
        for(int i =0;i<n;++i){
            p*=nums[i];
            pre[i]=p;
        }
        int s = 1;
        for(int i=n-1;i>=0;--i){
            s*=nums[i];
            post[i]=s;
        }
        res[0] = post[1];
        res[n-1]=pre[n-2];
        for(int i =1;i<=n-2;++i){
            res[i] = pre[i-1]*post[i+1];
        }
        return res;
    }
};