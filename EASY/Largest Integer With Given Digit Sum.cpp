class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = -1;
        // if(n==1) return s;
        for(int i=0;i<pow(10,n);i++){
            int demo = i;
            int check = 0;
            while(demo > 0){
                check += demo%10;
                demo /= 10;
            }
            if(check == s) ans = i;
        }
        return ans;
    }
};
