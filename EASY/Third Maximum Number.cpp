// Brute Force.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        vector<int> ans(s.begin(),s.end());

        if(ans.size()==1) return ans[0];
        if(s.size()==2) return max(ans[0],ans[1]);
        return ans[ans.size()-3];
    }
};
