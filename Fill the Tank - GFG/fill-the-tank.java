// { Driver Code Starts
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input_line[0]);
            int S = Integer.parseInt(input_line[1]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int cap[] = new int[N+1];
            for(int i=0;i<N;i++){
                cap[i] = Integer.parseInt(input_line1[i]);
            }
            int Edges[][] = new int[N+1][2];
            for(int i=0;i<N-1;i++){
                String input_line2[] = read.readLine().trim().split("\\s+");
                Edges[i][0] = Integer.parseInt(input_line2[0]);
                Edges[i][1] = Integer.parseInt(input_line2[1]);
            }
            Solution ob = new Solution();
            long ans = ob.minimum_amount(Edges, N, S, cap);
            System.out.println(ans);
        }
    }
}


// } Driver Code Ends


class Solution{
    
    long x = (long)Math.pow(10,18);
    int[] vis;
    boolean p;
    long minimum_amount(int [][]Edges, int N, int S, int []cap){
        // Code here
        p = false;
        ArrayList<ArrayList<Integer>> a = new ArrayList<>();
        int n = N;
        vis = new int[n+1];
        while(n>=0)
        {
            a.add(new ArrayList<Integer>());
            n--;
        }
        for (int[] e : Edges)
        {
            a.get(e[0]).add(e[1]);
            a.get(e[1]).add(e[0]);
        }
        long y = ch(a, N, S, cap);
        //System.out.println(y);
        if (p)
        return -1;
        return y>x?-1:y;
    }
    
    public long ch(ArrayList<ArrayList<Integer>> a, int n, int s, int[] c)
    {
        if (p)
        return -1;
        if (vis[s] == 1)
        return 0;
        vis[s] = 1;
        long max = 0;
        long no = 0;
        for (int i : a.get(s))
        {
            if (vis[i] == 0)
            {
                max = Math.max(ch(a, n, i, c), max);
                no++;
                if (max>x)
        {
            p = true;
            return -1;
        }
            }
        }
        if (max*no>x)
        {
            p = true;
            return -1;
        }
        return (c[s-1]+max*no);
    }
    
}
