class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size(),0);
        int a = 0,size = nums.size();

        for(int i=0;i<2*nums.size();i++){
            ans[i] = nums[a];
            a++;
            if(a==size) a = 0;
        }

        return ans;
    }
};
