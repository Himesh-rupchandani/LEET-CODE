class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){

            int pro = 1,store = i;

            while(store>0){
                pro *= store%10;
                store /= 10;
            }

            if(pro%t==0) return i;
        }
        return 0;
    }
};
