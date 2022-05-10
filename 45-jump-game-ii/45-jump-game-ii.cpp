class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int count = 0;
        int n = nums.size();
        for(int i = start; i<nums.size(); i = start){
            if(i == n-1)
                return count;
            count++;
            if(i + nums[i] >= n-1)
                return count;
            int next = start;
            int maxsteps = nums[i];
            for(int j = i; j < n and j<= (i + nums[i]); j++){
                if(next + maxsteps < j + nums[j]){
                    next = j;
                    maxsteps = nums[j];
                }
            }
           
            start = next;
        }
        return count;
    }
};