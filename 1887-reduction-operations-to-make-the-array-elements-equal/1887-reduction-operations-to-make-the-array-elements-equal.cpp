class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i-1] < nums[i]){
                res += (n - i);
            }
        }
        return res;
    }
};