class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck));
  vector<int> res(deck.size(), 0);
  res[0] = deck[0];
  for (auto i = 1, p = 0; i < deck.size(); ++i) {
    for (auto j = 0; j < 2; p %= res.size(), j += (res[p] == 0 ? 1 : 0)) ++p;
    res[p] = deck[i];
  }
  return res;
    }
};