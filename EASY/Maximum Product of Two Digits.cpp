class Solution {
public:
    int maxProduct(int n) {
       int max1 = 0, max2 = 0, divi;
       while(n>0){
            divi = n % 10;
            if(divi>max1){
                max2 = max1;
                max1 = divi;
            }
            else if(divi>max2) max2 = divi;
            n /= 10;
       } 

       return max1 * max2;
    }
};
