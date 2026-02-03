class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int counter = 0;
        for(auto c: s){
            if(c=='('){
                if(counter>0)
                res+=c;
                counter++;
            }
            else if(c==')'){
                counter--;
                if(counter>0) res+=c;
            }
        }
        return res;
    }
};