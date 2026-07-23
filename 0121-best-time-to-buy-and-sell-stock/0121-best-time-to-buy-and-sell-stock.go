func maxProfit(prices []int) int {
    maxProf := 0
    minCost:= prices[0]
    for i:=1; i<len(prices); i++{
        minCost = min(prices[i], minCost)
        maxProf = max(maxProf, prices[i]-minCost)
    }
    return maxProf
}