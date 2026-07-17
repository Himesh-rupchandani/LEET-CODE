class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        vector<int> prefixGcd(nums.size());
        int n = nums.size(),maxx = nums[0];
        long long int sum = 0;

        for(int i=0;i<nums.size();i++){
            if(maxx < nums[i]) maxx = nums[i];
            prefixGcd[i] = gcd(nums[i],maxx);
        }   

        sort(prefixGcd.begin(),prefixGcd.end());

        for(int left=0,right = n-1; left<right; left++,right--){
            sum += gcd(prefixGcd[left],prefixGcd[right]);
        }
        return sum;
    }
};
