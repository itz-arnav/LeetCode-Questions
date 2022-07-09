class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int count=1,ans=0;
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i+1]==nums[i])
               continue;
           if(nums[i+1]-nums[i]==1)
               count++; 
           else
           {
               ans=max(count,ans);
               count=1;
           }
                  
        }
        ans=max(count,ans);
        return ans;
    }
};