class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j = 0,k = 0;
        string s;

        while(i<word1.size() && j<word2.size()){
            s.push_back(word1[i]);
            k++;
            s.push_back(word2[j]);
            i++;
            j++;
            k++; 
        }   
        if(i<word1.size()){
            while(i<word1.size()){
                s.push_back(word1[i]);
                k++;
                i++;
            }
        }
        else if(j<word2.size()){
            while(j<word2.size()){
                s.push_back(word2[j]);
                k++;
                j++;
            }
        }
        return s;
    }
};
