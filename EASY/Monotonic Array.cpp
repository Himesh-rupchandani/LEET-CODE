class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt = 0;
        if(nums[0]<nums[nums.size()-1]){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]<=nums[i+1]) continue;
                else cnt = 1; 
            } 
        }

        else{
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>=nums[i+1]) continue;
                else cnt = 1; 
            } 
        }

        if(cnt==0) return true; 
        else return false;
    }
};
