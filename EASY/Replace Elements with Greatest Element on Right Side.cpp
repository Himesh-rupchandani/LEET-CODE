class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int largest = 0;
        if(arr.size()==1) arr[0] = -1;
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>largest){
                    largest = arr[j];
                    arr[i] = largest;
                }
            }
            largest = 0;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
