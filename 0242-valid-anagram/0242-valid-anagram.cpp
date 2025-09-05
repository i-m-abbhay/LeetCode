class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> mapS, mapT;
        for(int i=0; i<s.size();i++){
            mapT[t[i]]++;
            mapS[s[i]]++;
        }
        
        return mapS == mapT;;
        
    }
};