class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string result = "";
        while(i>=0 or j>=0 or carry){
            int total = carry;
            if(i>=0){
                total += (a[i]-'0');
                i-=1;
            }
            if(j>=0){
                total+=(b[j]-'0');
                j-=1;
            }
            result.append(to_string(total%2));
            carry = total/2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};