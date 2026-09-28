class Solution {
public:
    int maxDepth(string s) {
        int maxx = 0,current = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                current++;
            }
            else if(s[i]==')'){
                current--;
            }
            if(current>maxx){
                maxx = current;
            }
        }
        return maxx;
    }
};
