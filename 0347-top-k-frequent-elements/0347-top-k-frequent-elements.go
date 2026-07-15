func topKFrequent(nums []int, k int) []int {
  count := make(map[int]int)

  for _, num := range nums {
    count[num]++
  }  
  size := len(nums)
  buckets := make([][]int, size + 1)

  for val, freq := range count {
    buckets[freq] = append(buckets[freq], val)
  }

    res := []int{}
    res_count := 0

    for i:= len(buckets)-1; i>=0;i--{
        for _, val := range buckets[i]{
            if k<=res_count {
                break
            }
            res = append(res, val)
            res_count++
        }
         if k<=res_count {
                break
            }
    }
    return res
}