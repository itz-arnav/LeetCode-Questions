class Solution {
public:
    static bool cmp(int as, int bs){
        string a = to_string(as);
        string b= to_string(bs);
        for(int i = 0; i<a.size() and i < b.size(); i++){
            if(a[i] < b[i])
                return false;
            else if(a[i] > b[i])
                return true;
        }
        
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for(auto &x : nums){
            ans.append(to_string(x));
        }
        if(ans[0] == '0' and ans[1] == '0')
            ans = "0";
        return ans;
    }
};