class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

        // startTime hour
        int hs1 = startTime[0] - '0';
        int hs2 = startTime[1] - '0';
        int hs3 = (hs1*10) + hs2;
        int sum1 = hs3*60*60;

        // startTime minute
        int ms1 = startTime[3] - '0';
        int ms2 = startTime[4] - '0';
        int ms3 = (ms1*10) + ms2;
        int sum2 = ms3*60;

        // startTime secound
        int ss1 = startTime[6] - '0';
        int ss2 = startTime[7] - '0';
        int ss3 = (ss1*10) + ss2;
        int sum3 = ss3;

        // endTime hour
        int he1 = endTime[0] - '0';
        int he2 = endTime[1] - '0';
        int he3 = (he1*10) + he2;
        int sum4 = he3*60*60;     

         // endTime minute
        int me1 = endTime[3] - '0';
        int me2 = endTime[4] - '0';
        int me3 = (me1*10) + me2;
        int sum5 = me3*60;

        // startTime secound
        int se1 = endTime[6] - '0';
        int se2 = endTime[7] - '0';
        int se3 = (se1*10) + se2;
        int sum6 = se3;

        return((sum4+sum5+sum6) - (sum1+sum2+sum3));
    }
};
