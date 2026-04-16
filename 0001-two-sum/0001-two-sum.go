func twoSum(nums []int, target int) []int {
    for i, num := range nums {
        for j := i+1; j< len(nums); j++ {
            if target == num + nums[j]{
                return []int{i,j}
            }
        }
    }
    return []int{0,0}
}