func threeSum(nums []int) [][]int {
    sz := len(nums)
    res := [][]int{}
    sort.Ints(nums)

    for i:=0;i<sz-2;i++{
        if i>0 && nums[i-1] == nums[i]{
            continue
        }
        l, r := i+1, sz-1
        for l<r {
            sum := nums[i] + nums[l] + nums[r] 
            if sum==0 {
                res = append(res, []int{nums[i], nums[l], nums[r]})
                for l < r && nums[l] == nums[l+1]{
                    l++
                }
                for r>l && nums[r] == nums[r-1]{
                    r--
                }
                l++
                r--
            }
            if sum<0 {
                l++
            } else if sum > 0{
                r--
            }
        }
    }
    return res
}