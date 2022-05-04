class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ans;
        int k = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                ans.push_back(k);
                k=0;
            }
            else
                k++;
        }
        ans.push_back(k);
        if(ans.size()==1)
            return ans[0]-1;
        
        int maxx = 0;
        for(int i = 1; i<ans.size(); i++){
            maxx = max(maxx, ans[i] + ans[i-1]);
        }
        return maxx;
    }
};