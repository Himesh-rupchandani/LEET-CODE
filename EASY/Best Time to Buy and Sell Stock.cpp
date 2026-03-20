class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX,maximum = INT_MIN,size=0;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<minimum){
                minimum = prices[i];
                size = i;
            }
        }

        for(int i=size;i<prices.size();i++){
            if(prices[i]>maximum){
                maximum = prices[i];
            }
        }

        return maximum - minimum;
    }
};
