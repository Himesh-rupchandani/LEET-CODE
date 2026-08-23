class Solution {
public:
    bool isPalindromic(string s) {
        string ans;
        string demo = "        ";
        
        for(int i=0;i<s.size();i++){
            int value = int(s[i]);
            string demo = bitset<8>(value).to_string();    
            ans += demo;
        }

        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
