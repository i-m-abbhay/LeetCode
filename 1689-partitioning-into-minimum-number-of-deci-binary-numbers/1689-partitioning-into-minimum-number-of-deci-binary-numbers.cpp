class Solution {
public:
    int minPartitions(string str) {
        int n = str.size();
        int maxDig = 0;
        if(n==0) return 0;
        int i = 0;
        while(i<n){
            maxDig = max(maxDig, str[i]-'0');
            i++;
        }
        return maxDig;
    }
};