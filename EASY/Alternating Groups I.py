class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        cnt = 0
        for i in range(1,len(colors)-1):
            if colors[i]!=colors[i-1] and colors[i]!=colors[i+1]:
                cnt += 1
            
        if colors[0]!=colors[1] and colors[0]!=colors[-1]:
            cnt += 1
            
        if colors[-1]!=colors[-2] and colors[-1]!=colors[0]:
            cnt += 1

        return cnt
