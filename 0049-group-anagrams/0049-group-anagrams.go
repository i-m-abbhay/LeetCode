func groupAnagrams(strs []string) [][]string {
    //Time: O n*klogk Space On*k
    // Sorted key hash map sorted 
    // groups := make(map[string][]string)

    // for _, s := range strs{ //for every string
    //     b := []byte(s)

    //     sort.Slice(b, func(i, j int)bool{
    //         return b[i]<b[j] //O nlogn
    //     })
    //     key:= string(b)
    //     groups[key] = append(groups[key], s)
    // }

    // res := make([][]string, 0, len(groups))
    // for _, g := range groups{
    //     res = append(res, g)
    // }
    // return res

    //Count-key hash map for avoiding sorting
    //Time O n*k Space O n*k
    groups := make(map[[26]int][]string)
    for _, s := range strs {
        var count [26]int
        for _, c := range s {
            count[c-'a']++
        }
        groups[count] = append(groups[count], s)
    }

    res := make([][]string, 0, len(groups))
    for _, g := range groups {
        res = append(res, g)
    }
    return res
}