class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        for i in range(0,len(nums)):
            maxx = max(nums[0:i+1])
            minn = min(nums[i:len(nums)])
            value = maxx - minn
            if value <= k:
                return i
        return -1
