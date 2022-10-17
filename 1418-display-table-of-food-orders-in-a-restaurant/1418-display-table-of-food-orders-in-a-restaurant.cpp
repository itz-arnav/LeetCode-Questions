class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& o) {
        map<string,int> food;
        map<int, map<string,int>> mp;
        for(auto x : o){
            int val = stoi(x[1]);
            mp[val][x[2]]++;
            food[x[2]]++;
        }
        vector<vector<string>> ans;
        auto it = mp.begin();
        for(int i = 0; i<= mp.size(); ++i){
            vector<string> temp;
            if(i == 0){
                temp.push_back("Table");
                for(auto x : food){
                    temp.push_back(x.first);
                }
                ans.push_back(temp);
            }
            else{
                int now = it->first;
                temp.push_back(to_string(now));
                for(auto x : food){
                    temp.push_back(to_string(mp[now][x.first]));
                }
                ans.push_back(temp);
                ++it;
            }
        }
        return ans;
    }
};