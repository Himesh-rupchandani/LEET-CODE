class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());

        for(int x: nums){
            if(x!=mn && x!=mx) return x;
        }
        return -1;
    }
};
