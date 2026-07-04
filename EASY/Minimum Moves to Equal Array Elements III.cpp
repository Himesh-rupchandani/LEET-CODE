class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i=0,cnt = 0;;
        int maxx = *max_element(nums.begin(),nums.end());

        while(i!=nums.size()){
            if(nums[i]!=maxx){
                cnt++;
                nums[i] += 1;
            }
            else i++;
        }

        return cnt;
    }
};
