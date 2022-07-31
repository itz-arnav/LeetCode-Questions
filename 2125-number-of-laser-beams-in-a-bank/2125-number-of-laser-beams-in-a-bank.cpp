class Solution {
public:
    int numberOfBeams(vector<string>& arr) {
        int ans = 0;
        int prev = 0;
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 0; i<m; ++i){
            if(arr[0][i] == '1')
                prev++;
        }
        for(int i = 1; i<n; ++i){
            int curr = 0;
            for(int j = 0; j<m; ++j){
                if(arr[i][j] == '1')
                    curr++;
            }
            if(prev != 0 and curr != 0){
                ans += (curr* prev);

                prev = curr;
            }
             else if(prev == 0){
                prev = curr;
            }
        }
        return ans;
    }
};