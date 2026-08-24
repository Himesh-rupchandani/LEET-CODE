class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        for(int i=0;i<accounts.size();i++){
            int current_sum = 0;
            for(int j=0;j<accounts[0].size();j++){
                current_sum += accounts[i][j];
            }
            if(current_sum > sum) sum = current_sum;
        }
        return sum;
    }
};
