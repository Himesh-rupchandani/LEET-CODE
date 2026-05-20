class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m=INT_MIN,n=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>m) m = nums[i];
            if(nums[i]<n) n = nums[i]; 
        }

        int maxx,minn,ans;

        maxx = m;
        minn = n;

        for(int i=1;i<=maxx;i++){
            if(maxx%i==0 && minn%i==0) ans = i;
        }

        return ans;
    }
};
