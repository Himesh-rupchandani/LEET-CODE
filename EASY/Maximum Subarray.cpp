class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0,maxsum = INT_MIN;

        for(int i=0;i<nums.size();i++){

            currentsum += nums[i];
            maxsum = max(currentsum,maxsum);

            if(currentsum < 0) currentsum = 0;
        }

        return maxsum;
    }
};
