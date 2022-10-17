class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int i, int j) {
        vector<vector<int>> arr;
        arr.push_back({i,j});
        int gap=1;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        while(arr.size() < n*m){
            //right
            int ct = 0;
            while(ct < gap){
                j++;
                if(i >= 0 and j>= 0 and i<n and j<m and !visited[i][j]){
                arr.push_back({i,j});
                    visited[i][j] = true;
                }
                ct++;
            }
            //down
            ct = 0;
            while(ct<gap){
                i++;
                if(i >= 0 and j>= 0 and i<n and j<m and !visited[i][j]){
                arr.push_back({i,j});
                    visited[i][j] = true;
                }
                ct++;
            }
            //left
            gap++;
            ct = 0;
            while(ct < gap){
                j--;
                if(i >= 0 and j>= 0 and i<n and j<m and !visited[i][j]){
                arr.push_back({i,j});
                    visited[i][j] = true;
                }
                ct++;
            }
            //top
            ct = 0;
             while(ct < gap){
                i--;
                if(i >= 0 and j>= 0 and i<n and j<m and !visited[i][j]){
                arr.push_back({i,j});
                    visited[i][j] = true;
                }
                ct++;
            }
            gap++;
        }
        return arr;
    }
};