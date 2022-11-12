class Solution {
     public static int gcd(int a, int b) {
        if(a == 0)
            return b;
         
         return gcd(b%a, a);
    }
    public int subarrayGCD(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int curr_gcd = 0;
            for (int j = i; j < n; j++) {
                curr_gcd = gcd(curr_gcd, nums[j]);
                if(curr_gcd == k)
                    ans++;
            }
        }

        return ans;
    }

   
}