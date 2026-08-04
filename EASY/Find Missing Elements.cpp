class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());

        int i = 0;
        int minn = nums[0];
        int maxx = nums[nums.size()-1];

        while(i<nums.size()){
            if(nums[i] == minn){
                minn++;
                i++;
            }
            else{
                ans.push_back(minn);
                minn++;
            }
        }
        
        return ans;

    }
};
