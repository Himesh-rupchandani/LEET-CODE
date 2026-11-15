class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        c,d = 0,0
        for i in range(0,len(s)//2):
            if s[i].lower() in 'aeiou':
                c += 1
            if s[i+len(s)//2].lower() in 'aeiou':
                d += 1
       
        return c==d
