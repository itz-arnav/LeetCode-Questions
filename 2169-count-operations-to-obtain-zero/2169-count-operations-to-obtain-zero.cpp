class Solution {
public:
    int countOperations(int a, int b) {
        int res = 0;
    while (min(a, b) > 0) {
        if (a > b)
            swap(a, b);
        res += b / a;
        b %= a;
    }
    return res;
    }
};