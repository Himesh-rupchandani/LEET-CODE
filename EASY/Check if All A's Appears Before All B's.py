class Solution:
    def checkString(self, s: str) -> bool:
        cntb = 0
        for i in s:
            if i=='b':
                cntb+=1
            if cntb>0:
                if i=='a':
                    return False
        return True
