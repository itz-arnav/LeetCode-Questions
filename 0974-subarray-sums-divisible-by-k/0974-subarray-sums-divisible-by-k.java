class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int hash[] = new int[k+1];
        hash[0] = 1;
        int current_sum = 0;
        int ans = 0;
        for(int i = 0; i<nums.length; ++i){
            current_sum += nums[i];
            current_sum %= k;
            if(current_sum < 0)
                current_sum += k;
            ans += hash[current_sum];
            hash[current_sum]++;
        }
        return ans;
    }
}