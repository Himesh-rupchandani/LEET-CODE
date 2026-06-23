class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt4 = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') cnt1++;
            else if(moves[i]=='D') cnt2++;
            else if(moves[i]=='L') cnt3++;
            else cnt4++;
        }
        if(cnt1==cnt2 && cnt3==cnt4) return true;
        return false;
    }
};
