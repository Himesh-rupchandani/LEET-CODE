class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int frq = 0;

            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]) frq++;
            }
            if(frq==1) sum += nums[i];
        }
        return sum;
    }
};
