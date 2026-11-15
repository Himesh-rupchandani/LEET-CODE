class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        ans  = [0]
        for i in range(0,len(gain)):
            ans.append(ans[i]+gain[i])
        return max(ans)
