class Solution {
public:
    int minPartitions(string str) {
        int maxDig = 0;
        for(char ch: str)
            maxDig = max(maxDig, ch-'0');
        return maxDig;
    }
};