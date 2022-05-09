class Solution {
public:
     bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
    vector<int> left = nums, right(n, INT_MAX);
    
    for(int i = 1; i < n; i++)
        left[i] = min(left[i - 1], nums[i]);
    
    map<int, bool> mp;
    mp[nums[n - 1]] = true;
    for(int i = n - 2; i >= 0; i--)
    {
        auto it = mp.lower_bound(nums[i]);
        if(it != mp.begin())
            right[i] = (--it)->first;
        
        mp[nums[i]] = true;
    }
    
    for(int i = 1; i < n - 1; i++)
        if(right[i] > left[i - 1] && nums[i] > right[i])
            return true;
    
    return false;
    }
};