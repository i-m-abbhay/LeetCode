class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int numOfJewels = 0;

        for (char c : stones) {
            if (jewelSet.count(c)) {
                numOfJewels++;
            }
        }
        return numOfJewels;
    }
};
