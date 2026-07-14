func twoSum(nums []int, target int) []int {
    //Brute force: check every pair
    // Time On2 Space O1
    
    // for i:= 0; i<len(nums);i++{
    //     for j := i+1; j<len(nums);j++{
    //         if nums[i]+nums[j] == target {
    //             return []int{i, j}
    //         }
    //     }
    // }
    // return nil

    seen := make(map[int]int)
    for i, n:= range nums{
        if j, ok := seen[target-n]; ok {
            return []int{i, j}
        }
        seen[n] = i
    }
    return nil

}