class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        for(int i = start; i<nums.size(); i = start){
            
            int next = start;
            int maxsteps = nums[i];
            for(int j = i; j < n and j<= (i + nums[i]); j++){
                if(next + maxsteps < j + nums[j]){
                    next = j;
                    maxsteps = nums[j];
                }
            }
            if(next + maxsteps >= n-1)
                return true;
            if(start == next)
                return false;
            start = next;
        }
        return true;
    }
};