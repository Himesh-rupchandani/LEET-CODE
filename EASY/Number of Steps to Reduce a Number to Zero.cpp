class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0,divi;

        while(num>0){
            if(num%2!=0){
                num = num-1;
                cnt++;
                continue;
            } 

            num = num / 2;
            cnt++;
        }
        return cnt;
    }
};
