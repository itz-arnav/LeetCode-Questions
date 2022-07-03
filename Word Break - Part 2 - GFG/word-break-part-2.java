// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.stream.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(in.readLine());
            String arr[] = in.readLine().trim().split("\\s+");
            List<String> dict = new ArrayList<String>();
            for(int i = 0;i < n;i++)
                dict.add(arr[i]);
            String s = in.readLine();
            
            Solution ob = new Solution();
            List<String> ans = new ArrayList<String>();
            ans = ob.wordBreak(n, dict, s);
            if(ans.size() == 0)
                System.out.println("Empty");
            else{
                List<String> sol = ans.stream().sorted().collect(Collectors.toList());
                for(int i = 0;i < sol.size();i++)
                    System.out.print("("+sol.get(i)+")");
                System.out.println();
            }
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution{
    
    private static void rec(int ind, String res, String s, HashSet<String> hs, List<String> ans,  int n)
    {
        if(ind==n)
        {
            ans.add(res);
            return;
            
        }
        
        for(int i=ind; i<n; i++)
        {
            String part = s.substring(ind, i+1);
            if(hs.contains(part))
            {
                rec(i+1, res + part + (i+1==n ? "" : " "), s, hs, ans, n);
            }
        }
        
    }
    
    static List<String> wordBreak(int n, List<String> dict, String s)
    {
        HashSet<String> hs = new HashSet<>();
        
        for(String x  : dict)
        {
            hs.add(x);
        }
        
        List<String> ans = new ArrayList<>();
        
        rec(0, "", s, hs, ans, s.length());
        
        return ans;
        
    }
}