class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0
        for i in range(0,len(s)):
            inx = int(ord('z')-ord(s[i])+1)
            ans += inx * (i+1)
        return ans
