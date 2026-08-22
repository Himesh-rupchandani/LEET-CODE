class Solution:
    def checkDivisibility(self, n: int) -> bool:
        summ = 0
        pro = 1
        copy = n

        while(n>0):
            divi = n%10
            summ += divi
            pro *= divi
            n //= 10

        total = summ + pro

        if copy%total==0:
            return True
            
        return False
