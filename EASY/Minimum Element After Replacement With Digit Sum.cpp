class Solution {
public:
    int minElement(vector<int>& nums) {
           for(int i=0;i<nums.size();i++){
           int divi,sum = 0;
                while(nums[i]>0){
                    divi = nums[i]%10;
                    sum += divi;
                    nums[i] /= 10;
                }

                nums[i] = sum;
            }

            sort(nums.begin(),nums.end());
            return nums[0];
    }
};
