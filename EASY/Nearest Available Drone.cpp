class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1,copy = -100,pvalue = INT_MAX;
      
        for(int i=0;i<drones.size();i++){
            int value1 = abs( drones[i][0] - target[0]);
            int value2 = abs( drones[i][1] - target[1]);
            int value = value1 + value2;
            
            if(value <= drones[i][2]){
                if(value == copy) continue;
                else if(value < pvalue){
                     ans = i;
                     pvalue = value;
                     copy = value;
                }  
            }
        }
        return ans;
    }
};
