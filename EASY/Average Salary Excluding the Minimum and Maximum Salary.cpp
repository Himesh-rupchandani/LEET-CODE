class Solution {
public:
    double average(vector<int>& salary) {
        double minimum = INT_MAX;
        double maximum = INT_MIN;
        double answer = 0,cnt = salary.size()-2;

        for(int i=0;i<salary.size();i++){
            if(salary[i]<minimum) minimum = salary[i];
            if(salary[i]>maximum) maximum = salary[i];
            answer += salary[i];
        }

        return (answer-minimum-maximum)/cnt;
    }
};
