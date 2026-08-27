class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        if n%2==0:
            k = 1
            i = n//2-1
            j = n//2

            while i>=0 and j<n:
                ans.insert(i,k)
                ans.insert(j,-k)
                i -= 1
                j += 1
                k += 1

        else:
            k = n//2
            ans.insert(k,0)
            i = k - 1
            j = k + 1
            while i>=0 and j<n:
                ans.insert(i,k)
                ans.insert(j,-k)
                i -= 1
                j += 1
                k += 1
        return ans
