class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> st;
        vector<int> dp(nums.size(), 0);
        int res = 0;
        for(int i = nums.size() - 1; i >= 0 ;i--){
            if(st.empty()){
                st.push_back(i);
            }else{
                int count = 0;
                while(!st.empty() && nums[st.back()] < nums[i]){
                    count = max(count + 1, dp[st.back()]);
                    st.pop_back();
                }
                dp[i] = count;
                res = max(res, count);
                st.push_back(i);
            }
        }
        return res;
    }
};