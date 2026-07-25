class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int i = edges[0][0];
        int j = edges[0][1];

        if(edges[1][0]==i) return i;
        else if(edges[1][1]==i) return i;
        return j;
    }
};
