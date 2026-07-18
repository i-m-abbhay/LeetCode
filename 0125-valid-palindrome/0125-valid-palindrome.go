func isPalindrome(s string) bool {
    l, r := 0, len(s)-1

    for l < r {
        if !unicode.IsDigit(rune(s[l])) &&
            !unicode.IsLetter(rune(s[l])) {
            l++
            continue
        }

        if !unicode.IsDigit(rune(s[r])) &&
            !unicode.IsLetter(rune(s[r])) {
            r-- 
            continue
        }

        if unicode.ToLower(rune(s[l])) != unicode.ToLower(rune(s[r])) {
            return false
        }

        l++
        r--
    }

    return true
}