class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<arr.size(); ++i){
            mp[arr[i]].push_back(i);
        }
        
        for(int i = 1; i<=arr.size(); ++i){
            vector<int> temp;
            int ct = 0;
            for(int j = 0; j<mp[i].size(); ++j){
                ct++;
                temp.push_back(mp[i][j]);
                if(ct == i){
                    ans.push_back(temp);
                    temp.clear();
                    ct = 0;
                }
            }
        }
        return ans;
    }
};