class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int price : prices){
            minPrice = min(minPrice, price);              // best buy so far
            maxProfit = max(maxProfit, price - minPrice); // profit if sold today
        }
        return maxProfit;
    }
};
