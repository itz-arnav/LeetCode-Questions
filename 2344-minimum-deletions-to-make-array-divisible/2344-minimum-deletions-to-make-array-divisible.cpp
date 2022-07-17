class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& arr) {
        int ans = 0;
        unordered_map<int,int> mp;
        set<int> st;
        for(auto &x: nums){
            mp[x]++;
            st.insert(x);
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(auto &x: st){
            if(x > arr[0])
                return -1;
            bool flag = true;
            for(int i = 0; i<n; ++i){
                if(arr[i]%x != 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return ans;
            else
                ans += mp[x];
        }
        return -1;
        
    }
};