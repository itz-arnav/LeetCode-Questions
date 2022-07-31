class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i = 0; i<tokens.size(); ++i){
            if(tokens[i] == "-"){
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = to_string(stoi(y) - stoi(x));
                st.push(z);
            }
            else if(tokens[i] == "+"){
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = to_string(stoi(y) + stoi(x));
                st.push(z);
            }
            else if(tokens[i] == "*"){
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = to_string(stoi(y) * stoi(x));
                st.push(z);
            }
            else if(tokens[i] == "/"){
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = to_string(stoi(y) / stoi(x));
                st.push(z);
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};