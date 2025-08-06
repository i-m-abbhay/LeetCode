class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff_bits = x ^ y;
        int count = 0; 
        //now counting the set bits in diff_bits
        while(diff_bits){
            count += diff_bits & 1;
            diff_bits>>=1;
        }
        return count;
    }
};