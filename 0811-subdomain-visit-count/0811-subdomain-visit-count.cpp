class Solution {
public:
    vector<string> subdomainVisits(vector<string>& arr) {
        unordered_map<string,int> mp;
        for(int i = 0; i<arr.size(); ++i){
        vector <string> tokens;
        stringstream check1(arr[i]);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
        tokens.push_back(intermediate);
        }
        int val = stoi(tokens[0]);
        
        string &temp = tokens[1];
            int j = temp.size() - 1;
            string t = "";
            while(j >= 0){
                if(temp[j] == '.'){
                    mp[t] += val;
                }
                t.push_back(temp[j]);
                j--;
            }
            reverse(temp.begin(), temp.end());
            mp[temp] += (val);
        }
        
        vector<string> ans;
        for(auto &x : mp){
            string temp = x.first;
             reverse(temp.begin(), temp.end());
            ans.push_back(to_string(x.second) + " " + temp);
        }
        return ans;
    }
};