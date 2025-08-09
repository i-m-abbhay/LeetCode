class Solution {
public:

    //recursive solution
    bool isPowerOfTwo(int n){
        if(n<0) return false;
        long long set_bit_count = 0;
        while(n){
            if(1&n){
                set_bit_count++;
            }
            n = n>>1;
        }
        return set_bit_count == 1 ? true : false; 

    // bool isPowerOfTwo(int n) {
    // if (n <= 0) return false;
    // return !(n & (n - 1));
}

};