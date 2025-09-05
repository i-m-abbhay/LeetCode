class Solution {
public:
    
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            unsigned char L = (s[l]);
            unsigned char R = (s[r]);

            if(!isalnum(L)) { ++l; continue;}
            if(!isalnum(R)) { --r; continue;}

            if(tolower(L)!=tolower(R)) return false;
            ++l; --r;
        }
        return true;
    }
};