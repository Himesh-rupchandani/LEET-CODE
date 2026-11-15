class Solution:
    def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
        n1 = ''
        n2 = ''
        for i in word1:
            n1+=i
        for i in word2:
            n2+=i
        return n1==n2
