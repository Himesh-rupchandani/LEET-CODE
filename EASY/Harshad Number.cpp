class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int divi,sum = 0,y = x;
        while(x>0){
            divi = x%10;
            sum  += divi;
            x /= 10;
        }

        if(y%sum==0) return sum;
        else return -1; 
    }
};
