class Solution {
public:
    int xorOperation(int n, int start) {
        int answer = 0;
        vector<int> nums;

        for(int i=0;i<n;i++){
            int cnt = start + 2*i;
            nums.push_back(cnt);
            answer ^= nums[i];
        }
        return answer;
    }
};
