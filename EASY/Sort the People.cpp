class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        for(int i=0;i<names.size();i++){

            int maxx = heights[i];
            int index = i;

            for(int j=i+1;j<heights.size();j++){
                if(heights[j] > maxx){
                    maxx = heights[j];
                    index = j;
                }
            }

            swap(names[i],names[index]);
            swap(heights[i],heights[index]);
        }

        return names;
    }
};
