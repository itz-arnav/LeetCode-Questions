class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = -10006;
        int ct = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != x){
                if(ct == 0){
                    ct = 1;
                    x = nums[i];
                }
                else{
                    ct--;
                }
            }
            else{
                ct++;
            }
        }
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == x)
                ans++;
        }
        if(2*ans >= nums.size())
            return x;
        else
            return -1;
    }
};