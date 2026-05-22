class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;

        for(int fast = 1;fast<nums.size();fast++){
            if(nums[slow]!=0) slow++;

            else{
                if(nums[fast]!=0){
                    swap(nums[slow],nums[fast]);
                    slow++;
                }
            }
        }
    }
};
