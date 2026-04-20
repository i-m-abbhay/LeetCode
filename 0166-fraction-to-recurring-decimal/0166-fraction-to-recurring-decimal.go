func fractionToDecimal(numerator int, denominator int) string {
    if numerator == 0{
        return "0"
    }
    var result string

    if(numerator < 0) != (denominator < 0){
        result += "-"
    }

    n:= int64(numerator)
    d := int64(denominator)

    if n<0 {
        n=-n
    }
    if d < 0{
        d = -d
    }

    result +=strconv.FormatInt(n/d, 10)
    remainder := n%d

    if remainder == 0 {
        return result
    }
    result += "."

    seen := make(map[int64]int)
    for remainder != 0{
        if pos, exists:= seen[remainder]; exists{
            result = result[:pos] + "(" + result[pos:]+")"
            break
        }
        seen[remainder] = len(result)
        remainder *= 10
        result += strconv.FormatInt(remainder/d, 10)
        remainder %= d
    }
    return result
}