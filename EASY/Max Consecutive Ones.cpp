class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0,total = 0, grandtotal = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                total = cnt;
                if(total>grandtotal) grandtotal = total;
            } 
            else cnt = 0;
        }

        return grandtotal;
    }
};
