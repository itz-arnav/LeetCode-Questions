class Solution {
public:
    string smallestNumber(string s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i<=s.size(); ++i){
            st.push(i + '1');
            if(i == s.size() or s[i] == 'I'){
                while(st.size()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};