class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<2) return s;
        int bestStart = 0, bestLen = 1;
        
        auto expand = [&](int L, int R){
            while(L>=0 && R<n && s[L]==s[R]){
                int currentLen = R-L+1;
                if(currentLen>bestLen){
                    bestLen = currentLen;
                    bestStart = L;
                }
                --L;++R;
            }
        };

        for(int i=0;i<n;i++){
            expand(i, i);
            expand(i, i+1);
        }
        return s.substr(bestStart, bestLen);
    }
};