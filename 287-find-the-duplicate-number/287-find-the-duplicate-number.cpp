class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0){
                index = abs(nums[i]);
                break;
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 0)
                nums[i]*= -1;
        }
        return index;
    }
};