class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>> m;
        for(auto &x : str){
            string temp = x;
            sort(temp.begin(), temp.end());
            m[temp].push_back(x);
        }
        vector<vector<string>> ans;
        int i = 0;
        for(auto &it : m){
            vector<string> temp;
            ans.push_back(temp);
            vector<string> y = it.second;
            for(auto &z : y){
                ans[i].push_back(z);
            } 
            i++;
        }
        return ans;
    }
};