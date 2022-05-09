class Solution {
public:
    bool solve(vector<int> mod, int n, int k)
    {
        if (mod[k] < 1)
            return false;
        mod[k]--;
        int sum = k;
        bool alice;
        for (int i = 1; i < n; i++)
        {
            if (mod[1] && (sum + 1) % 3 != 0)
                mod[1]--, sum += 1;
            else if (mod[2] && (sum + 2) % 3 != 0)
                mod[2]--, sum += 2;
            else if (mod[0] > 0 && (sum) % 3 != 0)
                mod[0]--;
            else
                return i & 1;
        }
        return false;
    }

    bool stoneGameIX(vector<int> &v)
    {
        vector<int> mod(3);
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            mod[v[i] % 3]++;
        }
        return solve(mod, n, 2) || solve(mod, n, 1);
    }
};