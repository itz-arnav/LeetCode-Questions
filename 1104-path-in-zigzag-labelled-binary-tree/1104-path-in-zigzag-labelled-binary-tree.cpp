
    class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        //label is at which level
        int level = log(label) / log(2) + 1;
        //cout << level << endl;

        vector<int> res = {};
        
        int val = label;

        while(level)
        {

            res.emplace_back(val);
            // max_number + min_number - label
            val = pow( 2, (level-1) ) + pow(2, level) - 1 - val;
            
            val = val / 2;
            
            level--;
                
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
