class Solution {
public:
    string convertToTitle(int columnNumber) {
        string colName = "";
        while(columnNumber){
            int remainder = (columnNumber - 1) % 26;
            char c = 'A' + remainder;
            colName.push_back(c);
            columnNumber = (columnNumber - 1) / 26;
        }    
        reverse(colName.begin(), colName.end());
        return colName;
    }
};