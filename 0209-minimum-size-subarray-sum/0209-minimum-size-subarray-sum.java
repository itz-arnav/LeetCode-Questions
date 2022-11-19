class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int length = nums.length + 1;
        
        int current_sum = 0;
        int start_index = 0;
        for(int i = 0; i<nums.length; ++i){
            current_sum += nums[i];
            
            while(current_sum >= target){
                length = Math.min(length, i - start_index + 1);
                current_sum -= nums[start_index];
                start_index++;
            }
        }
        
        
        if(length > nums.length){
            return 0;
        }
        else{
            return length;
        }
    }
}