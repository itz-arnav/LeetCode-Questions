class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back({arr[0][0], arr[0][1]});
        int k = 0;
        for(int i = 1; i<arr.size(); ++i){
            if(arr[i][0] > ans[k][1]){
                ans.push_back({arr[i][0], arr[i][1]});
                k++;
            }
            else{
                ans[k][1] = max(ans[k][1], arr[i][1]);
            }
        }
        return ans;
    }
};