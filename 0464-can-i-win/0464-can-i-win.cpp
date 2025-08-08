class Solution {
    unordered_map<int, bool> memo;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(sum<desiredTotal) return false;
        if(desiredTotal<=0) return true;
        return canPlayerWin(0, desiredTotal, maxChoosableInteger);
    }
    bool canPlayerWin(int usedNumbers, int desiredTotal, int maxChoosableInteger){
        if(memo.count(usedNumbers)) return memo[usedNumbers];
        for(int i=1;i<=maxChoosableInteger;++i){
            int currentBit = (1<<i);
            if((usedNumbers&currentBit)==0){
                if(i>=desiredTotal ||
                !canPlayerWin(usedNumbers|currentBit, desiredTotal-i, maxChoosableInteger)){
                    return memo[usedNumbers] = true;
                }
            }
        }
        return memo[usedNumbers] = false;
    }
};