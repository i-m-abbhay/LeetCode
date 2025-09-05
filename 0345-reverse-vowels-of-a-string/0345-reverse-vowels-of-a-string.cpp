class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            if(!isVowel(s[l])){
                l++;
            }
            if(!isVowel(s[r])){
                r--;
            }
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l], s[r]);
                l++;r--;
            }
        }
        return s;
    }
private:
    bool isVowel(char c) {
        // normalize to lowercase
        c = tolower(c);  
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

};