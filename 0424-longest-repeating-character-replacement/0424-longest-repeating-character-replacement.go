func characterReplacement(s string, k int) int {
    sz := len(s)
    count := make(map[byte]int)
    longest := 0
    maxCount := 0
    left := 0
    for right := 0; right<sz; right++{
        c := s[right] // A, A, B, A
        count[c]++ // A: 2, B: 1
        maxCount = max(maxCount, count[c]) // 2
        windowLen := right-left+1 // 3
        if windowLen - maxCount>k{
            count[s[left]]--
            left++ //l->1
        }
        longest = max(longest, right-left+1) //3        
    }
    return longest
}