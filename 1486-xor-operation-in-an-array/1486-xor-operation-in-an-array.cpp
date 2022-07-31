class Solution {
public:
    int xorOperation(int n, int start) {
        int x = 0;
        for(int j = 0; j<n; ++j){
            x = x^(start+2*j);
        }
        return x;
    }
};