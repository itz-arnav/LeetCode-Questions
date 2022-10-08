class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); ++i){
            if(ans.size() <= index[i]){
                ans.push_back(nums[i]);
            }
            else{
                ans.insert(ans.begin() + index[i], nums[i]);
            }
        }
        return ans;
    }
};