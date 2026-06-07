class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        int a = 0,divi,copy = left,check;

        while(left<=right){
            divi = copy%10;
            if(divi==0){
                left++;
                copy = left;
                continue;
            }
            check = left%divi;

            if(check==0){
                if(copy>9){
                    copy = copy/10;
                    continue;
                }
                else{
                    answer.push_back(left);
                    a++;
                    left++;
                    copy = left;
                }

            }
            else{
                left++;
                copy = left;
            }
        }

        return answer;   
    }
};
