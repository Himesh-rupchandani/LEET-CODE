class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        sort(nums.begin(),nums.end());
        set<int> s(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                ans[0] = nums[i];
            }
        }
        vector<int> v(s.begin(),s.end());

        for(int i=0;i<v.size();i++){
            if(i+1!=v[i]){
                ans[1] = i+1;
                return ans;
            }
        }
        if(ans[1] == 0) ans[1] = v[v.size()-1] + 1;
        return ans;
    }
};
