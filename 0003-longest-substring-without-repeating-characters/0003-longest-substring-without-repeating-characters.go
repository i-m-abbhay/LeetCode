func lengthOfLongestSubstring(s string) int {
    seen := map[byte]int{}
    left:=0
    longest:=0
    for right:=0; right<len(s);right++{
        c := s[right]
        if lastInd, ok := seen[c]; ok && lastInd>=left{
            left = max(left, lastInd+1)
        }
        seen[c] = right
        longest = max(longest, right-left+1)
    }
    return longest
}