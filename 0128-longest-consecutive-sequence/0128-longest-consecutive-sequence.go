func longestConsecutive(nums []int) int {
    numsSet := make(map[int]bool)
    for _,num:=range nums{
        numsSet[num]=true // 100->t, 4->t 200->t 1->t 3-> t 2->t
    }

    longest := 0
    for num:= range numsSet{ //100->t
        currLen := 0
        if !numsSet[num-1]{
            currLen++ // 1
            for numsSet[num+1] {
            currLen++
            num++ // 101
            }
            longest = max(currLen, longest) // 1
        }
        
    }
    return longest
}