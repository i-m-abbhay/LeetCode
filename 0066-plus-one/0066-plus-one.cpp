class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> out;
        int carry = 1;                     
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            out.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) out.push_back(carry);    
        reverse(out.begin(), out.end());
        return out;
    }
};
