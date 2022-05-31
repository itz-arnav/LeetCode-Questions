class Solution {
public:
    int power(int a, int n){
        if(n == 0)
            return 1;
        if(n == 1)
            return a;
        
        int res = 1;
        while(n){
            if(n&1){
                res *= a;
                n--;
            }
            else{
                a*=a;
                n>>=1;
            }
        }
        return res;
    }
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (k > n) return false;
        unordered_set<int> st;
        for (int i = 0; i + k <= n; i++){
            int temp = 0;
            for(int j = 0; j<k; j++){
                int curr = s[i+j] - '0';
                temp |= (curr<<j);
            }
            st.insert(temp);  
        }
        int total_subsets = power(2,k);
        return (st.size() == total_subsets);
            
    }
};