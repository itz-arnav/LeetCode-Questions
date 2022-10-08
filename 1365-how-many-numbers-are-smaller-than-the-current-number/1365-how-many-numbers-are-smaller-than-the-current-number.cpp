class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int n=  nums.size();
        for(int i = 0; i<n; ++i){
            int ct = 0;
            for(int j = 0; j<n; ++j){
                if(nums[j] < nums[i])
                    ct++;
            }
            ans.push_back(ct);
        }
        return ans;
    }
};