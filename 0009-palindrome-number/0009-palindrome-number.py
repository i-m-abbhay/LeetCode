class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        if x==0:
            return True
        numbers = []
        flg = True
        while(x):
            numbers.append(x%10)
            x=x//10
        for i in range(len(numbers)):
            if(numbers[i]!=numbers[len(numbers)-i-1]):
                return False
        return flg