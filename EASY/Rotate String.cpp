class Solution {
public:
    bool rotateString(string s, string goal) {

        string add = s + s;
        if(s.size() != goal.size()) return false;
        if(add.find(goal) != string::npos) return true;
        return false;
    }
};
