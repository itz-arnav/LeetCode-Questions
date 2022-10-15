class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> arr;
        for(int i = 0; i<points.size(); ++i){
            arr.push_back(points[i][0]);
        }
        sort(arr.begin(), arr.end());
        int best = 0;
        for(int i = 1; i<arr.size(); ++i){
            best = max(best, arr[i] - arr[i-1]);
        }
        return best;
    }
};