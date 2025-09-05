class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mgz;
        for(int i=0;i<magazine.size();i++){
            mgz[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mgz[ransomNote[i]]<=0){
                return false;
            }
            mgz[ransomNote[i]]--;
        }
        return true;
    }
};