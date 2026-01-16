class Solution {
public:
    string reverseWords(string s) {
        // vector<string> strvec;
        // string str ="";
        // for(int i =0;i<=s.size();i++){
        //     if(i==s.size() || s[i]==' ') {
        //         if(!str.empty()) strvec.push_back(str);
        //         str.clear();
        //     } else {
        //         str+=s[i];
        //     }
        // }
        
        // reverse(strvec.begin(), strvec.end());
        // str="";
        // for(int i=0;i<strvec.size();i++){
        //     str+=strvec[i];
        //     if(i!=strvec.size()-1) str+=" ";
        // }
        // return str;

        reverse(s.begin(), s.end());
        int n = (int)s.size();
        int i = 0;
        int write = 0;

        while(i<n){
            while(i<n && s[i] == ' ')i++;
            if(i>=n) break;

            if(write>0) s[write++]=' ';

            int wordStart = write;
            while(i<n && s[i] != ' '){
                s[write++] = s[i++];
            }
            reverse(s.begin()+wordStart, s.begin()+write);
        }
        s.resize(write);
        return s;
    }
};