class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till_now=prices[0], max_diff_till_now = 0;
        for(int i=1;i<prices.size();i++){
            min_till_now = min(min_till_now, prices[i]);
            max_diff_till_now = max(prices[i]-min_till_now, max_diff_till_now);
        }
        return max_diff_till_now;
    }
};