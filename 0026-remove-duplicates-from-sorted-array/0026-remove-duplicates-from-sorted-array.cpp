class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[start])
                continue;
            else
                nums[++start] = nums[i];
        }
        return start+1;
    }
};