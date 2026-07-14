func topKFrequent(nums []int, k int) []int {
    //Sort by frequency
    // time O(n log n) Space On
    // count := make(map[int]int)

    // for _, n := range nums {
    //     count[n]++
    // }
    // keys := make([]int, 0, len(count))
    // for key := range count {
    //     keys = append(keys, key)
    // }
    // sort.Slice(keys, func(i, j int) bool {
    //     return count[keys[i]]>count[keys[j]]
    // })

    // return keys[:k]

    //Bucket Sort bucket index = frequency
    //Time On Space On
    count := make(map[int]int)
    for _, n:= range nums {
        count[n]++
    }

    buckets := make([][]int, len(nums)+1)
    for num, freq := range count {
        buckets[freq] = append(buckets[freq], num)
    }

    res := make([]int, 0, k)
    for f:= len(buckets) - 1; f >= 0 && len(res) < k; f-- {
        for _, num := range buckets[f]{
            res = append(res, num)
            if len(res)==k {
                break
            }
        }
    }
    return res

}