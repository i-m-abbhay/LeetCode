func maxArea(height []int) int {
    l, r := 0, len(height)-1
    maxA := 0
    for l<r{
        maxA = max(maxA, (r-l)*min(height[l], height[r]))
        if height[l]>height[r]{
            r--
        } else {
            l++
        }
    }
    return maxA
}