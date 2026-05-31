class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int divi;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int copy = nums[i];
            while(copy>0){
                divi = copy%10;
                sum += divi;
                copy /= 10;
            }
            if(sum==i) return i;
        }  

        return -1; 
    }
};
