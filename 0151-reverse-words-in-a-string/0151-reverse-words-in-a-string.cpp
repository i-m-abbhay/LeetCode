class Solution {
public:
    string reverseWords(string s) {
        vector<string> strvec;
        string str ="";
        for(int i =0;i<=s.size();i++){
            if(i==s.size() || s[i]==' ') {
                if(!str.empty()) strvec.push_back(str);
                str.clear();
            } else {
                str+=s[i];
            }
        }
        
        reverse(strvec.begin(), strvec.end());
        str="";
        for(int i=0;i<strvec.size();i++){
            str+=strvec[i];
            if(i!=strvec.size()-1) str+=" ";
        }
        return str;
    }
};