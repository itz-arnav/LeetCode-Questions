class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, mid = 0, end = nums.size()-1;
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                start++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};