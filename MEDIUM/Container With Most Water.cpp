class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right = height.size()-1;
        int maxWater = 0;

        while(left < right){

            int width = right - left;
            int ht = min(height[right],height[left]);
            int currentWater = width * ht;

            maxWater = max(currentWater,maxWater);

            if(height[right] < height[left]) right--;
            else left++;
        }

        return maxWater;
    }
};
