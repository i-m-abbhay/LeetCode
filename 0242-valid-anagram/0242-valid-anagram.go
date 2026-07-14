func isAnagram(s string, t string) bool {
    // Brute force Sorting
    // sort both strings and check if they are same
    //Time O nlogn Space On (for keeping original intact)

    // if len(s)!=len(t){
    //     return false
    // }
    // sb, tb := []byte(s), []byte(t)
    // sort.Slice(sb, func(i, j int) bool {return sb[i]<sb[j]}) 
    // sort.Slice(tb, func(i, j int) bool {return tb[i]<tb[j]})
    // return string(sb)==string(tb)

    //Hash Map: compare the character freq coutns
    // Time On Space O1 --bounded alphabets

    if len(s)!= len(t){
        return false
    }
    count := make(map[rune]int)
    for _, c := range s{
        count[c]++
    }
    for _, c := range t{
        count[c]--
        if(count[c]<0){
            return false
        }
    }
    return true
}