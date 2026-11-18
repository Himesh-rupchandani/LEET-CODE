class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic = {
            'a' : 0,
            'b' : 0,
            'l' : 0,
            'o' : 0,
            'n' : 0
        }
        for i in text:
            if i in dic:
                dic[i]+=1
        cnt = 0
        while(1):
            if dic['a']>=1 and dic['b']>=1 and dic['l']>=2 and dic['o']>=2 and dic['n']>=1:
                dic['a'] -= 1
                dic['b'] -= 1
                dic['l'] -= 2            
                dic['o'] -= 2
                dic['n'] -= 1
                cnt+=1
            else:
                return cnt
