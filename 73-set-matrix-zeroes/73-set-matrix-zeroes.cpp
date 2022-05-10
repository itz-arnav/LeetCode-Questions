class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        bool first_col = false;
        bool first_row = false;
        for(int i = 1; i<m; i++)
            if(arr[0][i] == 0)
                first_col = true;
        
        for(int i = 1; i<n; i++)
            if(arr[i][0] == 0)
                first_row = true;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(arr[i][j] == 0){
                    arr[0][j] = 0;
                    arr[i][0] = 0;
                }
                
            }
        }
        for(int i = 1; i<m; i++){
            if(arr[0][i] == 0){
                for(int j = 1; j<n; j++){
                    arr[j][i] = 0;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            if(arr[i][0] == 0){
                for(int j = 1; j<m; j++){
                    arr[i][j] = 0;
                }
            }
        }
        int x = arr[0][0];
        if(x == 0 or first_row){
            for(int i =  0; i<n; i++)
               arr[i][0] = 0;
        }
        if(x == 0 or first_col){
            for(int i = 0; i<m; i++)
                arr[0][i] = 0;
        }
        
    }
};