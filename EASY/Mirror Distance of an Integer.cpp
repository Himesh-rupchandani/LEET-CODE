class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,m;
        m = n;

        while(n>0){
            rev = (rev*10) + n%10;
            n = n/10;
        }
        return abs(m-rev);
        
    }
};
