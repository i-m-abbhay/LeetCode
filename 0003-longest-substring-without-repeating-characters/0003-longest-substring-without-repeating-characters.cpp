class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastInd (256, -1);
        int start = 0, maxLen = 0;
        for(int i=0;i<s.size();i++){
            if(lastInd[s[i]]>=start){
                start = lastInd[s[i]] + 1;
            }
            lastInd[s[i]] = i;
            maxLen = max(maxLen, i-start+1);
        } 
        return maxLen;
    }
};