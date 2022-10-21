class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        if(mink > maxk)
            return 0;
        long long ans = 0;
        long long curr_min = nums[0];
        long long curr_max = nums[0];
        int n = nums.size();
        long long st = 0;
        long long last0 = 0, last1 = 0;
        for(int i = 0; i<n; ++i){
            curr_min = min(curr_min, (long long)nums[i]);
            curr_max = max(curr_max, (long long)nums[i]);
            if(nums[i] == mink){
                last0 = i;
            }
            if(nums[i] == maxk){
                last1 = i;
            }
            if(curr_min == mink and curr_max == maxk){
                ans+=min(last0, last1) - st + 1;
            }
            else if((curr_max > maxk or curr_min < mink) and i < n-1){
                curr_min = curr_max = nums[i+1];
                st = i+1;
            }
            else if(i == n-1){
                break;
            }            
        }
        return ans;
    }
};