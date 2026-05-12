class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int TotalSum = 0, sumOfArray=0;

        TotalSum = nums.size()*(nums.size()+1)/2;

        for(int i=0;i<nums.size();i++){
            sumOfArray += nums[i];
        }

        return TotalSum-sumOfArray;
    }
};
