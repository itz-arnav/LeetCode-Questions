class Solution {
public:
    int countBalls(int l, int h) {
        int cnt[46] = {};
    for (auto i = l; i <= h; ++i) {
        int sum = 0, n = i;
        while(n) {
            sum += n % 10;
            n /= 10; 
        }
        ++cnt[sum];
    }
    return *max_element(begin(cnt), end(cnt));
        
    }
};