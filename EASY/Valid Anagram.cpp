// Brute force

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;
        return false;
    }
};

//Optimal

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if length's are not Equal.
        if(s.size()!=t.size()) return false;
        vector<int> frq(26,0); 

        // Store frequancy of character in s and t.
        for(int i=0;i<s.size();i++){
            frq[s[i] - 'a']++;
            frq[t[i] - 'a']--;
        }
        
        // Checking if frequancy of any character is zero.
        for(int i=0;i<26;i++){
            if(frq[i]!=0) return false; //not anagram.
        }

        return true;
    }
};
