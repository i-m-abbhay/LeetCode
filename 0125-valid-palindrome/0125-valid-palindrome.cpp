class Solution {
    string normalize(const string& input){
        string result;
        for(char ch:input){
            if(std::isalnum(static_cast<unsigned char>(ch))){
                result+=tolower(ch);
            }
        }
        return result;
    }
public:
    bool isPalindrome(string s) {
        string ss = normalize(s);
        int l=0, r=ss.length()-1;
        while(l<r){
            if(ss[l]!=ss[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};