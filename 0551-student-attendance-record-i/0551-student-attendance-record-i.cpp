class Solution {
public:
    bool checkRecord(string s) {
        int globalLateMax = 0,localLateMax=0;
        int totalAbsent = 0;
        for(int i =0;i<s.size(); i++){
            while(s[i]=='L'){
                localLateMax++;
                globalLateMax = max(globalLateMax, localLateMax);
                i++;
            }
                localLateMax=0;
            if(s[i]=='A'){
                totalAbsent++;
            }
        }
        return globalLateMax<3 && totalAbsent < 2;
    }
};