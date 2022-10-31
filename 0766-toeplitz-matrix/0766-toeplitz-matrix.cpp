class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1; i<n; i++){
            int j = 1;
            int c = i+1;
            while(c < n && j < m){
                if(matrix[c][j] != matrix[c-1][j-1])
                    return false;
                c++;
                j++;
            }
        }
        for(int j = 0; j<m; j++){
            int i = 1;
            int c = j+1;
            while(i < n && c < m){
                if(matrix[i][c] != matrix[i-1][c-1])
                    return false;
                i++;
                c++;
            }
        }
        return true;
    }
};