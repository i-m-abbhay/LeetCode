class Solution {
public:
    int titleToNumber(string columnTitle) {
        int colNumber = 0;
        for(int i=0;i<columnTitle.size();i++){
            colNumber += (columnTitle[i] - 'A' + 1 ) * pow(26,columnTitle.size() - i - 1);
        }
        return colNumber;
    }
};