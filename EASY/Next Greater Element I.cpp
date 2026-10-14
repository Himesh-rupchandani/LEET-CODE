class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int greater = INT_MAX;
            bool flag = false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    greater = nums2[j];
                }
                if(nums2[j]>greater){
                    ans.push_back(nums2[j]);
                    flag = true;
                    break;
                }
            }
            if(flag==false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
