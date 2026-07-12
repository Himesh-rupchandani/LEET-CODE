class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0],max_sum = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) sum += nums[i];
            else{
                max_sum = max(max_sum,sum);
                sum = nums[i];
            }
        }
        return max(max_sum,sum);   
    }
};
