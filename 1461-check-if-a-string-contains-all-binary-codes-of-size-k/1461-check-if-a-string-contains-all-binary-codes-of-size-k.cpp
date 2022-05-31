class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<int> st;
        
        for (int i = 0; i <= s.size()-k; i++){
            
            int temp = 0;
            for(int j = 0; j<k; j++){
                int curr = s[i+j] - '0';
                temp |= (curr<<j);
            }
            
            st.insert(temp);
            
        }
        
        return st.size() == pow(2, k);
    }
};