// High ms code

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        for(int i=0,j=0,k=0;k<nums.size();k++){
            if(k%2==0){
                if(nums[i] > 0){
                    ans.push_back(nums[i]);
                    i++;
                }
                else{
                    while(nums[i] < 0){
                        i++;
                    }
                    ans.push_back(nums[i]);
                    i++;
                }
            }

            else{
                if(nums[j] < 0){
                    ans.push_back(nums[j]);
                    j++;
                }
                else{
                    while(nums[j] > 0){
                        j++;
                    }
                    ans.push_back(nums[j]);
                    j++;
                }
            }
        }
        return ans;
    }
};



// Low ms code

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);

        for(int i=0,j=0,k=0;k<nums.size();k++){
            if(k%2==0){
                if(nums[i] > 0){
                    ans[k] = nums[i];
                    i++;
                }
                else{
                    while(nums[i] < 0){
                        i++;
                    }
                    ans[k] = nums[i];
                    i++;
                }
            }

            else{
                if(nums[j] < 0){
                    ans[k] = nums[j];
                    j++;
                }
                else{
                    while(nums[j] > 0){
                        j++;
                    }
                    ans[k] = nums[j];
                    j++;
                }
            }
        }
        return ans;
    }
};
