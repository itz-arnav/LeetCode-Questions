class Solution {
public:
    pair<int, int> memo[501][501] = {};
    bool stoneGame(vector<int>& piles) {
        auto [aliceScore, leeScore] = dp(piles, 0, piles.size() - 1);
        return aliceScore > leeScore;
    }
    pair<int, int> dp(vector<int>& piles, int left, int right) {
        if (left > right) return make_pair(0, 0);
        if (memo[left][right].first != 0) return memo[left][right];

        pair<int, int> leftPick = dp(piles, left + 1, right);
        pair<int, int> rightPick = dp(piles, left, right - 1);
        if (piles[left] + leftPick.second > piles[right] + rightPick.second) { // If the left choice has higher score than the right choice
            return memo[left][right] = make_pair(piles[left] + leftPick.second, leftPick.first); // then pick left
        }
        return memo[left][right] = make_pair(piles[right] + rightPick.second, rightPick.first); // else pick right
    }
};