class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current = 0,maxx;
        for(double i=0;i<k;i++){
            current += nums[i];
        }
        maxx = current;

        for(double i=1;i<=nums.size()-k;i++){
            current = current - nums[i-1] + nums[i+k-1];

            if(current>maxx) maxx = current; 
        }

        return maxx/k;
    }
};
