class Solution {
// private:
//     int numOfBits(int i){
//         int cnt=0;
//         while(i!=0){
//             if(i&1) cnt++;
//             i>>=1;
//         }
//         return cnt;
//     }
// public:
//     vector<int> countBits(int n) {
//         vector<int>res(n+1, 0);
//         for(int i=0;i<n+1;i++){
//             res[i] = numOfBits(i);
//         }
//         return res;
//     }
public:
    vector<int> countBits(int n){
        vector<int> res(n+1,0);
        for(int i = 1; i<=n;i++){
            res[i] = res[i>>1]+(i&1);
        }
        return res;
    }
};