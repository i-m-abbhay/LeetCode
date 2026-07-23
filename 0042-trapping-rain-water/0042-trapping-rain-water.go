func trap(height []int) int {
    sz := len(height)
    
    maxFromL := make([]int, sz)
    maxFromR := make([]int, sz)
    
    maxFromL[0] = height[0]
    maxFromR[sz-1] = height[sz-1]
    
    maxiL := maxFromL[0]
    maxiR := maxFromR[sz-1]
    
    totalWater := 0
    
    for i:= 1; i<sz; i++{
        maxFromL[i] = max(maxiL, height[i])
        maxiL = maxFromL[i] 
    }

    for i:=sz-2; i>=0; i-- {
        maxFromR[i] = max(maxiR, height[i])
        maxiR = maxFromR[i]
    }

    for i:=0;i<sz;i++{
        totalWater += min(maxFromL[i], maxFromR[i]) - height[i]
    }
    return totalWater
   
}