class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), res = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];
            res += count[prefix]*i - total[prefix];
            // cout<<"count added : "<<count[prefix]*i<<" total : "<<total[prefix]<<endl;
            count[prefix]++;
            total[prefix] += (i+1);
        }
        return res;
    }
};