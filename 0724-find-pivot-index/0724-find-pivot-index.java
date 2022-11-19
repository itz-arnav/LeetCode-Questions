class Solution {
    public int pivotIndex(int[] nums) {
        int totalWeightOnLeft = 0;
        int totalWeightOnRight = 0;
        for(int element : nums){
            totalWeightOnRight += element;
        }
        for( int i = 0 ; i < nums.length ; i++ ){
            int curWeight = nums[i];
            totalWeightOnRight -= curWeight;
            if( totalWeightOnLeft == totalWeightOnRight ){
                return i;
            }
            totalWeightOnLeft  += curWeight;
        }
        return -1;
    }
}