class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0,product = 1,divi;

        while(n>0){
            divi = n%10;
            sum = sum + divi;
            product = product*divi;
            n /= 10;
        }
        return product-sum;
    }
};
