class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); ++i){
            if(k == 0)
                break;
            
            if(nums[i] < 0){
                k--;
                nums[i] *= -1;
            }
            else{
                break;
            }
        }
        sort(nums.begin(), nums.end());
        if(k&1){
            nums[0] *= -1;
        }
        int s = 0;
        for(auto x : nums){
            s+=x;
        }
        return s;
    }
};