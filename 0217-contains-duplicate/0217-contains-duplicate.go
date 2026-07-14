func containsDuplicate(nums []int) bool {
    //brute force: compare every pair of elements
    // Time On2 space O1
    
    // for i:= 0; i<len(nums); i++{
    //     for j:= i+1; j<len(nums); j++{
    //         if nums[i]==nums[j]{
    //             return true
    //         }
    //     }
    // }
    // return false

    //Hash set: track the values seen so far
    // Time On Space On
    seen:= make(map[int]bool)
    for _, n := range nums {
        if seen[n] {
            return true
        }
        seen[n]= true
    }
    return false
}