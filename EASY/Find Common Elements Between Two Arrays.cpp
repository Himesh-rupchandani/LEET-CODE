class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0,j=0;
        int cnt1 = 0,cnt2 = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                cnt2++;
                j++;
            }
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }

        i = 0,j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                cnt1++;
                i++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }

        return {cnt1,cnt2};
    }
};
