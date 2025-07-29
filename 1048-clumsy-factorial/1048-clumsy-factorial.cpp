class Solution {
typedef long long ll;
public:
    int clumsy(int n) {
        int answer = 0;
        int sign = 1;
        for(int i=n;i>0;i-=4){
            ll temp = i;   // n
            if(i-1>0) temp *= i-1; // n*n-1
            if(i-2>0) temp /= i-2; // n*n-1/n-2
            answer += sign * temp; // +/-(n*n-1/n-2)
            if(i-3 > 0 ) answer += i-3; // +-(n*n-1/n-2) + n-3
            sign = -1;
        }
        return answer;
    }
};
