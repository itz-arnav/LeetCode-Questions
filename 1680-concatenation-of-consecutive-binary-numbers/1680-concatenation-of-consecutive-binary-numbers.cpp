class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) ans = ((ans << (32 - __builtin_clz(i))) % mod + i) % mod;
        return ans;
    }
};