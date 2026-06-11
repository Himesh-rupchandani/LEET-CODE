class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1;
        int slargest = -1;
        int index;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                slargest = largest;
                largest = nums[i];
                index = i;
            }

            else if(nums[i]<largest && nums[i]>slargest){
                slargest = nums[i];
            }
        }

        if(slargest*2>largest) return -1;
        else return index;
    }
};
