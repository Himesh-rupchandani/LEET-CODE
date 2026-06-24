class Solution {
public:
    int maxDistance(string moves) {
        int cntU = 0,cntD = 0,cntL = 0,cntR = 0,cnt_ = 0,cnt = 0;

        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') cntU++;
            else if(moves[i]=='D') cntD++;
            else if(moves[i]=='L') cntL++;
            else if(moves[i]=='R') cntR++;
            else cnt_++;
        }

        cntU = abs(cntU-cntD);
        cntR = abs(cntR-cntL);
        cnt = cntU + cntR + cnt_;
        
        return cnt;
    }
};
