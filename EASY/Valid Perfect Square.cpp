class Solution {
public:
    bool isPerfectSquare(int num) {
        int m = sqrt(num);
        if(m*m==num) return true;
        else return false;
    }
};
