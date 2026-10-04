class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX, sec_smallest = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < smallest){
                sec_smallest = smallest;
                smallest = prices[i];
            }
            else if(prices[i] < sec_smallest){
                sec_smallest = prices[i];
            }
        }
        int cost = smallest + sec_smallest;
        if(cost <= money){
            return money - cost;
        }
        return money;
    }
};
