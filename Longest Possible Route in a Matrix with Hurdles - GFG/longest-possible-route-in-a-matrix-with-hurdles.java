// { Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];
        
        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }
        
        return mat;
    }
    
    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
    
    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int[] a = IntArray.input(br, 2);
            
            
            int[] b = IntArray.input(br, 4);
            
            
            int[][] mat = IntMatrix.input(br, a[0], a[1]);
            
            Solution obj = new Solution();
            int res = obj.longestPath(mat,a[0],a[1],b[0],b[1],b[2],b[3]);
            
            System.out.println(res);
            
        }
    }
}
// } Driver Code Ends

class Solution {
   static int ans = -1;
   static int[][] dir = new int[][]{ {1,0} , {-1,0} , {0,1} , {0,-1} };
   static boolean isValid(int i, int j, int n, int m, int[][] mat, boolean[][] v){
       return i>=0 && i<n && j>=0 && j<m && mat[i][j] == 1 && v[i][j] == false;
   }
   static void helper(int[][] mat,boolean[][] v, int n,int m,int xs,int ys,int xd,int yd, int count){
       if(xs==xd && ys == yd){
           ans = Math.max(ans, count);
       }
       
       v[xs][ys] = true;
       for(int i=0;i<4;i++){
           int newx = xs + dir[i][0];
           int newy = ys + dir[i][1];
           if(isValid(newx,newy,n,m,mat,v)){ // range, not 0, not visited
               helper(mat, v, n, m, newx, newy, xd, yd, count+1);
               
           }
       }
       v[xs][ys] = false;
   }
   public static int longestPath(int[][] mat,int n,int m,int xs,int ys,int xd,int yd) {
       if(mat[xs][ys] == 0) return -1;
       boolean[][] visited = new boolean[n][m];
       helper(mat, visited, n, m, xs, ys, xd, yd,0);
       
       int t = ans; ans = -1; return t;
   }
}