class Solution {
public:
    bool squareIsWhite(string s) {
        int x = s[0] - 96;
        int y = s[1] - '0';
        return (x + y)&1;
    }
};