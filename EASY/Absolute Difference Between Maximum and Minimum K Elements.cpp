class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int cntmax = 0,cntmin = 0;
        int summax = 0,summin = 0;

        for(int i=nums.size()-1;cntmax<k;i--){
            summax += nums[i];
            cntmax++;
        }

        for(int i=0;cntmin<k;i++){
            summin += nums[i];
            cntmin++;
        }
        return (abs(summax - summin));
    }
};
