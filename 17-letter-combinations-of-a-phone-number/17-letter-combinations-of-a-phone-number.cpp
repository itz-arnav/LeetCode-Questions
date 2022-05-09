class Solution {
    public:
    const vector<string> arr = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string s) {
        if (s.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto c: s) {
            vector<string> temp;
            for(auto x: arr[c - '0']) {
                for(auto s: result) {
                    temp.push_back(s + x);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};