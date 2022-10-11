class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); ++i){
            if(ans.size() == 0){
                ans.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                if(it >= ans.size()){
                    ans.push_back(nums[i]);
                }
                else{
                    ans[it] = nums[i];
                }
            }
        }
        return ans.size() >= 3;
    }
};