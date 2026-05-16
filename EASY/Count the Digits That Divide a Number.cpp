class Solution {
public:
    int countDigits(int num) {
        int divi,cnt = 0,copy = num;

        while(num>0){
            divi = num%10;
            if(copy%divi==0) cnt++;
            num /= 10;
        }
        return cnt;
    }
};
