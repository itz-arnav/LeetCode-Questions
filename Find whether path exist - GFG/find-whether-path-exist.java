//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < n; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            boolean ans = obj.is_Possible(grid);
            if(ans)
                System.out.println("1");
            else 
                System.out.println("0");
        }
    }
}
// } Driver Code Ends



class Solution
{
    //Function to find whether a path exists from the source to destination.
    public boolean dfs(int i, int j, boolean[][] visited, 
    int[][] grid){
        if(i < 0  || j < 0 || i >= grid.length || j >= grid[0].length){
            return false;
        }
        if(grid[i][j] == 2){
            return true;
        }
        
        if(visited[i][j] || grid[i][j] == 0)
        return false;
        
        visited[i][j] = true;
        boolean ans = false;
        ans |= dfs(i+1, j, visited, grid);
        ans |= dfs(i-1, j, visited, grid);
        ans |= dfs(i, j+1, visited, grid);
        ans |= dfs(i, j-1, visited, grid);
        return ans;
    }
    
    public boolean is_Possible(int[][] grid)
    {
        int V = grid.length;
        boolean[][] visited = new boolean[V+1][V+1];
        
        
        for(int i = 0; i<V; ++i){
            for(int j = 0; j<V; ++j){
                if(grid[i][j] == 1)
                return dfs(i,j,visited, grid);
            }
        }
        return false;
    }
}