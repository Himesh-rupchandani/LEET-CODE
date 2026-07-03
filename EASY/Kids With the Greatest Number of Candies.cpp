class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= *max_element(candies.begin(),candies.end())){
                result[i] = true;
            }
            else result[i] = false; 
        }

        return result;
    }
};
