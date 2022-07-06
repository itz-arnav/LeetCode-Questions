class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2; i>=0; --i){
            if(nums[i] >= nums[i+1])
                continue;
            else{
                int j;
                for(j = n-1; j>i; --j){
                    if(nums[j] > nums[i]){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                if(j == i){
                    swap(nums[i], nums[i+1]);
                }
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        
        sort(nums.begin(), nums.end());
    }
};