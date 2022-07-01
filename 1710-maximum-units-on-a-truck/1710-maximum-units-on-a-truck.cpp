class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        double x = a[1];
        double y = b[1];
        return x > y;
    }
    int maximumUnits(vector<vector<int>>& arr, int truck) {
        sort(arr.begin(), arr.end(), cmp);
        
        int ans = 0;
        for(int i = 0; i<arr.size();++i){
            if(truck == 0)
                break;
            if(truck < arr[i][0]){
                ans += truck*arr[i][1];
                truck = 0;
                break;
            }
            else{
                ans += arr[i][0]*arr[i][1];
                truck -= arr[i][0];
            }
        }
        return ans;
    }
};