class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        unordered_map<int,int> win;
        unordered_map<int,int> loss;
        int n=  arr.size();
        for(int i = 0; i<n; i++){
            win[arr[i][0]]++;
            loss[arr[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto &x: win){
            if(loss[x.first] > 0)
                continue;
            else
                temp.push_back(x.first);
        }
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
        temp.clear();
        for(auto &x : loss){
            if(x.second == 1){
                temp.push_back(x.first);
            }
        }
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
        return ans;
    }
};