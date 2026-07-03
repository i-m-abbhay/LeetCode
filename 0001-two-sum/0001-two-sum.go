func twoSum(nums []int, target int) []int {
    // brute force (On2, O1)
    // n:= len(nums)
    // for i:= 0;i<n;i++{
    //     for j:= i+1; j<n; j++{
    //         if nums[i] + nums[j] == target{
    //             return []int{i,j}
    //         }
    //     }
    // }
    // return nil
    
    //Two pass hashmap (On, On)
    // seen := make(map[int]int)
    
    // for i, num := range nums {
    //     seen[num] = i;
    // } 
    
    // for i, num := range nums{
    //     complement := target - num
    //     if index, found := seen[complement]; found{
    //         return []int{i,index}
    //     } 
    // }
    // return nil

    //One pass hashmap (On, On)
    seen:= make(map[int]int)
    for i, num := range nums {
        complement := target - num
        if index, found := seen[complement]; found{
            return []int{index, i}
        }
        seen[num]=i
    }
    return nil
}