class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt = 0;
        
        for(int i=0;i<batteryPercentages.size();i++){
            if(batteryPercentages[i] - cnt > 0){
                cnt++;
            }
        }
        return cnt;
    }
};
