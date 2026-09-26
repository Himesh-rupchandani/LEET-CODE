class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> vec(heights.begin(),heights.end());
        sort(heights.begin(),heights.end());

        for(int i=0;i<heights.size();i++){
            if(vec[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};
