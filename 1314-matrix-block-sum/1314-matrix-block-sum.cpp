class Solution {
public:
   vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
       
       int m = mat.size();
       int n = mat[0].size();
       
       vector<vector<int>> t( m, vector<int> (n, 0));
       
       for(int i = 0; i < m; ++i){
           for(int j = 0; j < n; ++j){
               if( i == 0 && j == 0) t[i][j] = mat[i][j];
               else if( i == 0 ) t[i][j] = t[i][j-1] + mat[i][j];
               else if( j == 0 ) t[i][j] = t[i-1][j] + mat[i][j];
               else t[i][j] = mat[i][j] + t[i-1][j] + t[i][j-1] - t[i-1][j-1];
           }
       }
       
       vector<vector<int>> res(m, vector<int>(n,0));
       for(int i = 0; i < m; ++i){
           for(int j = 0; j < n; ++j){
               
               int x1 = max(0, i-k);
               int y1 = max(0, j-k);
               
               int x2 = min(i + k, m-1);
               int y2 = min(j + k, n-1);
               
               res[i][j] = t[x2][y2] - ( x1 > 0 ? t[x1-1][y2] : 0) - ( y1 > 0 ? t[x2][y1-1] : 0 ) + ( (x1 > 0 && y1 > 0) ? t[x1-1][y1-1] : 0 );  
           }
       }
       return res;
   }
};