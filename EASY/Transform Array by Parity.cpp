class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i] = 0;
            else nums[i] = 1;
        }

        int slow = 0,fast = 1;
        while(slow<nums.size() && fast<nums.size()){
            if(nums[slow]==0){
                slow++;
                fast++;
            }
            else if(nums[slow]==1 && nums[fast]==0){
                swap(nums[slow],nums[fast]);
                slow++;
                fast++;
            } 
            else fast++;
        }
        return nums;
    }
};
