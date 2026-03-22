class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0, GCD;
        sumOdd = n*n;
        sumEven = n*(n+1);

        int ans =__gcd(n,n*2);
        return ans;
    }
};
