class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        int ans = 0;
        map<int,int> mp;
        for(int i = 0; i<arr.size(); ++i){
            ans += mp[arr[i]];
            mp[arr[i]]++;
        }
        return ans;
    }
};