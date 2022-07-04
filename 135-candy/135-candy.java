class Solution {
    public int candy(int[] arr) {
        
        int n = arr.length;
        
        int [] l2r = new int[n];
        Arrays.fill(l2r,1);
        int [] r2l = new int[n];
        Arrays.fill(r2l,1);
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1])
                l2r[i] = l2r[i-1] + 1;
        }
        for(int i = n-2; i>=0; i--){
            if(arr[i] > arr[i+1])
                r2l[i] = r2l[i+1] + 1;
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += Math.max(l2r[i], r2l[i]);
        }
        return sum;
    }
}