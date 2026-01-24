class Solution {
public:
   int pivotInteger(int n) {
    int totalSum = n*(n+1)/2;
   
    int l=0,h=n;
    while(l<=h){
        int mid = l+(h-l)/2;
        int left = (mid-1)*mid/2;
        int right = totalSum-left - mid;
        if(left==right) return mid;
        else if(left>right) h = mid-1;
        else l=mid+1; 
    }
    return -1;
}
};