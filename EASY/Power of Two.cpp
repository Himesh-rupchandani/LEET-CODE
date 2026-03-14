class Solution {
public:
    bool isPowerOfTwo(long long int n) {
       return (n && !(n&(n-1)));
    }
};
