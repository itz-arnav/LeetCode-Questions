class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long,int> mp;
        int ans = 0;
        long sum = 0;
        mp[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            sum%=k;
            if(sum < 0)
                sum = (sum + k)%k;
            ans += mp[sum];
            
            mp[sum]++;
        }
        return ans;
    }
};