class Solution {
public:
   int addDigits(int num) {
    int temp = 0;
    if( num<10) return num;
    while(num>0){
        temp = temp + num%10;
        num = num/10;
    } 
    num = temp;
    return addDigits(num);
}
};