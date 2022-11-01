class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans(m,-1);

        //drop the ball from each coloumn and see where the ball goes
        for(int i=0;i<m;i++)
        {
            //call dfs function to see where the ball go
            int k=dfs(0,i,n,m,grid);  
            ans[i]=k;  //store the position
        }
        return ans;
    }

    int dfs(int row,int col,int n,int m,vector<vector<int>>&grid)
    {
        int nr=row;
        int nc=col+grid[row][col];
        if(nc<0 || nc>=m || grid[row][col]!=grid[nr][nc]){
            return -1;
        }

        nr++;
        if(nr>=n){
            return nc;
        }

        return dfs(nr,nc,n,m,grid);
    }
};