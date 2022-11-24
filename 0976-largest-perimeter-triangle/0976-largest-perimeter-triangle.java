class Solution {
    public int largestPerimeter(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int a = n-1, b=  n-2, c = n-3;
        while(c >= 0){
            int x = arr[a], y = arr[b], z = arr[c];
            if(x + y > z && x + z > y && y + z > x){
                return x + y + z;
            }
            else{
                a--;
                b--;
                c--;
            }
        }
        return 0;
    }
}