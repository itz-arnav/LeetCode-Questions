// { Driver Code Starts
//Initial Template for Java

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
            String s = br.readLine().trim();
            String[] S = s.split(" ");
            int[] nums = new int[n];
            for(int i = 0; i < n; i++){
                nums[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
            boolean ans = ob.brainGame(nums);
            if(ans)
                System.out.println("A");
            else 
                System.out.println("B");     
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public boolean brainGame(int[] nums)
   {
       // Code here
       int a[] = new int[1005];
       for(int i = 2; i<= 1000; i++){
     for(int j = 2*i; j <= 1000; j+=i)
      a[j] = Math.max(a[j], 1 + a[i]);
    }
    int x = 0;
    for(int i = 0; i < nums.length; i++){
     x = x ^ a[nums[i]];
    }
    if(x == 0)
     return false;
    return true;
   }
}