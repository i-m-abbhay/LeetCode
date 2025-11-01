class Solution {
public:
   int divide(int dividend, int divisor) {
    // Handle overflow
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign
    bool negative = (dividend < 0) ^ (divisor < 0);

    long long a = labs((long long)dividend);
    long long b = labs((long long)divisor);
    long long result = 0;

    while (a >= b) {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        result += multiple;
    }

    if (negative) result = -result;
    return (result > INT_MAX) ? INT_MAX : (int)result;
}

}; 