// import "sort"
func containsDuplicate(nums []int) bool {
    //bruteForce (On2, O1)
    // n := len(nums)

    // for i:= 0; i<n; i++ {
    //     for j:= i+1; j<n; j++{
    //         if nums[i] == nums[j]{
    //             return true
    //         }
    //     }
    // }
    // return false

    //the Sorting approach (Onlogn, O1)
    // sort.Ints(nums)
    // for i:= 0; i<len(nums)-1; i++{
    //     if nums[i] == nums[i+1]{
    //         return true
    //     }
    // }
    // return false

    //hash set approach (On, On)
    seen:= make(map[int]bool)
    for _, num := range nums{
        if seen[num] {
            return true
        }
        seen[num]=true
    }
    return false
}