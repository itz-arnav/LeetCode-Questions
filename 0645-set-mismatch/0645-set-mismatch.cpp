class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
    while(i < n) {
        
        int correct = arr[i] - 1;
        if(arr[i] != arr[correct])   
        swap(arr[i], arr[correct]);
        
        else {
            i++;
        }
    }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(arr[i] != i+1){
                ans.push_back(arr[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};