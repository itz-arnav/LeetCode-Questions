class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        int pick = arr[0], notpick = 0;
        for(int i = 1; i<n; ++i){
            int c = notpick + arr[i];
            int d = max(pick, notpick);
            pick = c;
            notpick = d;
        }
        return max(pick, notpick);
    }
};