class Solution {
public:
    int countEven(int num) {
        int copy,divi,cnt = 0,a = 1;

        for(copy=1;copy<=num;copy++){
            int sum = 0;
            while(copy>0){
                divi = copy%10;
                sum += divi;
                copy /= 10;
            }
            if(sum%2==0) cnt++;
            copy = a;
            a++;
        }
        return cnt;
    }
};
