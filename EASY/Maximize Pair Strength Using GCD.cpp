class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        unsigned long long int maxx = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                
                unsigned long long int value1 = (unsigned long long int)nums[i] * nums[j];

                unsigned long long int value2 = __gcd(nums[i],nums[j]);

                value2 *= value2;

                unsigned long long int ans = (unsigned long long int)value1/value2;

                if(maxx < ans) maxx = ans;
            }
        }

        return maxx;
    }
};
