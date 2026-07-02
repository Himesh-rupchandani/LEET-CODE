class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> memory;
        int sum = 0;

        for(int i=0;i<operations.size();i++){
            if(operations[i]!="C" && operations[i]!="D" && operations[i]!="+"){
                memory.push_back(stoi(operations[i]));
            }
            else if(operations[i]=="C") memory.pop_back();
            else if(operations[i]=="D"){
                int n = memory.size();
                memory.push_back(memory[n-1]*2);
            }
            else {
                int n= memory.size();
                memory.push_back(memory[n-1] + memory[n-2]);
            }
        }

        for(int i=0;i<memory.size();i++){
            sum += memory[i];
        }

        return sum;
    }
};
