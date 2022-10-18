class Solution {
public:
    string countAndSay(int n) {
    if (n == 1) return "1";
    string ans = "1";
    while (--n) {
        string temp = "";
        for (int i = 0; i < ans.size(); i++) {
            int count = 1;
             while ((i + 1 < ans.size()) && (ans[i] == ans[i + 1])){
                count++;    
                i++;
            }
            temp += to_string(count) + ans[i];
        }
        ans = temp;
    }
    return ans;
    }
};