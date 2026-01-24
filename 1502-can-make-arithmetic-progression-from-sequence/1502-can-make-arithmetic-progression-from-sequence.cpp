class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        //O(nlogn) approach
        // sort(arr.begin(), arr.end());
        // int diff = arr[1]-arr[0];
        // for(int i=2;i<arr.size();i++){
        //     if(diff!=arr[i]-arr[i-1]){
        //         return false;
        //     }
        // }

        //O(n) approach
        // We know the max - min should be divisible by n-1 
        int n = arr.size();
        int mn = INT_MAX, mx= INT_MIN;
        for(int x:arr){
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if(mn==mx) return true;
        int diff = mx-mn;
        if(diff%(n-1)!=0) return false;
        
        //now checking whether all the elements lie in one of the slot of mn+i*d or not
        int d = diff/(n-1);
        unordered_set<int> seen(arr.begin(), arr.end());
        for(int i = 0;i<n;i++){
            if(seen.find(mn+i*d)==seen.end()) return false;
        }
        return true;
    }
};