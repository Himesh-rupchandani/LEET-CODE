class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());

        double sum = 0,value = 0;

        int i = prices.size()-1;
        int j = discounts.size()-1;

        while(i>=0 && j>=0){
            value = double(prices[i]) * (100 - double(discounts[j]))/100;

            sum += value;
            i--;
            j--;
        }

        for(i;i>=0;i--){
            sum += double(prices[i]);
        }
        return sum;
    }
};
