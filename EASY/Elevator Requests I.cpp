class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum = 0,value = 0;
        for(int i=0;i<requests.size();i++){
            sum += abs(value - requests[i]);
            value = requests[i];
        }
        return sum;
    }
};
