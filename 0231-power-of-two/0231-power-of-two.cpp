class Solution {
public:

    //recursive solution
    bool isPowerOfTwo(int n){
        
        if(n==1) return true;
        if(n==0 || n%2 != 0) return false;
        return isPowerOfTwo(n/2);

    // bool isPowerOfTwo(int n) {
    // if (n <= 0) return false;
    // return !(n & (n - 1));
}

};