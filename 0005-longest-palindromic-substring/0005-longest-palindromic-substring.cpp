#include <string>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int bestStart = 0, bestLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length
            auto [l1, r1] = expandAroundCenter(s, i, i);
            if (r1 - l1 + 1 > bestLen) {
                bestLen = r1 - l1 + 1;
                bestStart = l1;
            }

            // Even length
            auto [l2, r2] = expandAroundCenter(s, i, i+1);
            if (r2 - l2 + 1 > bestLen) {
                bestLen = r2 - l2 + 1;
                bestStart = l2;
            }
        }
        return s.substr(bestStart, bestLen);
    }
    pair<int, int> expandAroundCenter(string s, int left, int right){
        while(left >=0 && right < s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};