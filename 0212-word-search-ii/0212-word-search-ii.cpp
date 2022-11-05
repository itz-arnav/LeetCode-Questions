class TrieNode {
    public:
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        child.resize(26, nullptr);
        isEnd = false;
    }
};

class Solution {
public:
    int rows, cols;
    void add(TrieNode * root, string & wrd) {
        for (char & ch : wrd) {
            if (root -> child[ch - 'a'] == nullptr) {
                root -> child[ch - 'a'] = new TrieNode();
            }
            root = root -> child[ch - 'a'];
        }
        root -> isEnd = true;
    }
    
    void dfs(TrieNode * root, vector<vector<char>>& mat, vector<string> & res, int i, int j, string &wrd) {
        if (mat[i][j] != '.' and root -> child[mat[i][j] - 'a'] != nullptr) {
            wrd.push_back(mat[i][j]);
            root = root -> child[mat[i][j] - 'a'];
            if (root -> isEnd) {
                root -> isEnd = false;
                res.push_back(wrd);
            }
            char tmp = '.';
            swap(tmp, mat[i][j]);
            if (i > 0) dfs(root, mat, res, i - 1, j, wrd);
            if (j > 0) dfs(root, mat, res, i, j - 1, wrd);
            if (i < rows - 1) dfs(root, mat, res, i + 1, j, wrd);
            if (j < cols - 1) dfs(root, mat, res, i, j + 1, wrd);
            swap(tmp, mat[i][j]);
            wrd.pop_back();
        }
    } 
    vector<string> findWords(vector<vector<char>>& mat, vector<string>& wrds) {
        TrieNode * root = new TrieNode();
        rows = mat.size(), cols = mat[0].size();
        vector<string> res;
        for (string & wrd : wrds) {
            add(root, wrd);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                string wrd = "";
                dfs(root, mat, res, i, j, wrd);
            }
        }
        return res;
    }
};