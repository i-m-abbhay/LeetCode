#include<bits/stdc++.h>
class Solution {
public:
    vector<string> splitTrimString(string s){
        vector<string> tokens;
        char delimiter = ' ';
        string token;
        stringstream ss(s);
        while(getline(ss, token, delimiter)){
            if(token!=""&&token!=" ") tokens.push_back(token) ;
        }
        return tokens;
    }
    string reverseWords(string s) {
        
        vector<string> splitted = splitTrimString(s);
        reverse(splitted.begin(),splitted.end());
        string result = splitted[0];
        for(int i=1;i<splitted.size();i++){
            result +=(" "+ splitted[i]);
        }
        return result;
    }
};