class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &x : queries){
            int ct = 0;
            for(auto &y : points){
                if((y[0]-x[0])*(y[0]-x[0]) + (y[1]-x[1])*(y[1]-x[1])<=x[2]*x[2])
                    ct++;
            }
            ans.push_back(ct);
        }
        return ans;
    }
};