class Solution {
public:
    unordered_map<int,int> mp;

    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        for(int i=0 ; i < nums.size() ; i++)
            mp[nums[i]] = i; //Save position of each value
        for(vector<int> a : operations) mp[a[1]] = mp[a[0]] , mp[a[0]] = -1; 
		// When a-> b we give position of a to b, mark that a is not in the array anymore
        for(auto i : mp)
            if(i.second >= 0) // If value is in array
                nums[i.second] = i.first;
        return nums;
    }
};