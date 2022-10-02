class Solution {
public:
    string s;
    vector<int> memo;
    int n;
    
    // taken from cp-algorithms
    vector<int> z_function(string& s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    int solve(int i){
        if(i == s.size()) return 0;
        if(memo[i] != -1) return memo[i];
        
        int result = 1;
        string sub = s.substr(i);
        vector<int> z = z_function(sub);
        int j = 1;
        
        while(j < z.size()){
            if(z[j] >= j) result = max(result, 1 + solve(i+j));
            j++;
        }
        
        return memo[i] = result;
    }
    
    int deleteString(string s) {
        this->memo = vector<int>(s.size(), -1);
        this->n = s.size();
        this->s = s;
        
        return solve(0);
    }
};