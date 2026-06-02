class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0,cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0 && nums[i]%2==0){
                sum += nums[i];
                cnt++;
            }
        }

        if(cnt==0) return sum;
        else return sum/cnt;
    }
};
