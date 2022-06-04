class Solution {
public:
    vector<string> a;
    vector<vector<string>> ans;
    
    bool check(int n,int row, int col){
        //check row first
        for(int i = 0; i<n; i++)
        {
            if(a[row][i] == 'Q'){
                    return false;
            }
        }
        //check column now
        
        for(int i = 0; i<n; i++){
            if(a[i][col] == 'Q'){
                    return false;
            }
        }
        
        //check low princi diag
        for(int i = 0; i<n; i++){
            if(row+i == n || col+i == n)
                break;
            if(a[row+i][col+i] == 'Q'){
                    return false;
            }
        }
        
        //check upper princi diag
        for(int i = 0; i<n; i++){
            if(row-i < 0 || col -i < 0)
            break;
            if(a[row-i][col-i] == 'Q'){
                    return false;
            }
        }
        
        //check other diagonal low
        
        for(int i = 0; i<n; i++){
            if(row +i == n || col - i <0)
            break;
            if(a[row+i][col-i] == 'Q'){
                    return false;
            }
        }
        
        //check other diagonal high
        for(int i = 0; i<n; i++){
            if(row -i <0 || col + i == n)
            break;
            if(a[row-i][col+i] == 'Q'){
                    return false;
            }
        }
        
        
        return true;
    }
    
    void helper(int n, int curr){
        if(curr == n){
            ans.push_back(a);
            return;
        }
        for(int i = 0; i<n; i++){//col iteration
            if(check(n,curr,i)){
                a[curr][i] = 'Q';
                helper(n, curr+1);
                a[curr][i] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string init = "";
        for(int i = 0; i<n; i++)
            init+='.';
        a = vector<string>(n,init);
        helper(n,0);
        return ans;
    }
};