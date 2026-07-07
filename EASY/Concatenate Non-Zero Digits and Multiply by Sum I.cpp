class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long int rev = 1,pro = 1,sum = 0;
        string s = to_string(n);
        string ans;

        for(int i=0;i<s.size();i++){
            int num = s[i] - '0';
            if(num != 0){
                sum += num;
                ans.push_back(s[i]);
            }
        }

        pro = stoi(ans);   

        return pro*sum;
    }
};
