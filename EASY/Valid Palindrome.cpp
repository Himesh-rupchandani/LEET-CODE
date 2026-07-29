class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0,j = s.size()-1;
        while(i<j){

            char ch1 = tolower(s[i]);
            char ch2 = tolower(s[j]);

            if(!isalnum(ch1)){
                i++;
                continue;
            }
            if(!isalnum(ch2)){
                j--;
                continue;
            }

            if(ch1 != ch2) return false;
            i++;
            j--;
        }
        return true;
    }
};
