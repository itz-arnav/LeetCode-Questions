class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for (int x : nums) {
            if (temp.empty() or x > temp[temp.size() - 1]) {
                temp.emplace_back(x);
            } 
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), x); 
                *it = x;
            }
        }
        return temp.size();
    }
};