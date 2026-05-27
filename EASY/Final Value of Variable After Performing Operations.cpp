class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int total = 0;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "--X" || operations[i] == "X--") total += -1;
            else total += 1;
        }

        return total;
    }
};
