class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int min_len_str = INT_MAX;
        for(auto &str: strs){
            min_len_str = min(min_len_str, (int)str.size());
        }
        string s = "";
        for(int j=0;j<min_len_str;j++){
            char c = strs[0][j];
            for (int i = 1; i<strs.size();i++){
                if(strs[i][j]!=c){
                    return s;
                }
            }
            s.push_back(c);
        }
        return s;
    }
};