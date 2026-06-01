class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> averages;
        sort(nums.begin(),nums.end());

        int j = nums.size();
        double mini = 0;
        double maxx = 0;

        for(int i=0;i<j/2;i++){

            maxx = nums[nums.size()-1];
            mini = nums[0];
            nums.erase(nums.begin());
            nums.pop_back();

            averages.push_back((maxx+mini)/2);
        }

        sort(averages.begin(),averages.end());
        return averages[0];
    }
};
