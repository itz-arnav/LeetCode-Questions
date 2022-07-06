class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int curr = 0, past = arr[0];
        for(int i = 0; i<n; ++i){
            curr = max(curr, arr[i]-past);
            past = min(past, arr[i]);
        }
        return curr;
    }
};