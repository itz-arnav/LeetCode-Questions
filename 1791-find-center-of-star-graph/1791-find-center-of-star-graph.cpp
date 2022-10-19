class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto x : edges){
            mp[x[0]]++;
            mp[x[1]]++;
        }
        int n=  edges.size();
        for(auto x : mp)
        {
            if(x.second == n)
                return x.first;
        }
        return -1;
    }
};