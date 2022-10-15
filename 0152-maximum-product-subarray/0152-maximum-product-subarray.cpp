class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int negative_so_far = 1, positive_so_far=1;
        for(auto i : nums){
            if(i > 0){
                
                positive_so_far *= i;
                negative_so_far *= i;
                
                ans = max(ans, positive_so_far);
                
                negative_so_far = min(negative_so_far, 1);
                positive_so_far = max(positive_so_far, 1);
                
            }
            else if(i < 0){
                
                int curr_negative = positive_so_far*i;
                int curr_positive = negative_so_far*i;
                
                positive_so_far = curr_positive;
                negative_so_far = curr_negative;
                
                ans = max(ans, positive_so_far);
                
                negative_so_far = min(negative_so_far, 1);
                positive_so_far = max(positive_so_far, 1);
            }
            else{
                negative_so_far = 1;
                positive_so_far = 1;
                ans = max(ans, 0);
            }
            
        }
        return ans;
    }
};