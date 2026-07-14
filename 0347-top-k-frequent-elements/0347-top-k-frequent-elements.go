func topKFrequent(nums []int, k int) []int {
    count := make(map[int]int)

    for _, n := range nums {
        count[n]++
    }
    keys := make([]int, 0, len(count))
    for key := range count {
        keys = append(keys, key)
    }
    sort.Slice(keys, func(i, j int) bool {
        return count[keys[i]]>count[keys[j]]
    })

    return keys[:k]
}