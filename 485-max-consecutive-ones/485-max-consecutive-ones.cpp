class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size();
        int ct = 0;
        int prev = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] == 1){
                prev++;
            }
            else{
                ct = max(ct, prev);
                prev = 0;
            }
        }
        ct = max(ct, prev);
        return ct;
    }
};