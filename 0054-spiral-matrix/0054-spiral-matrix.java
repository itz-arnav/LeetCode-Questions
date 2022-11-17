class Solution {
    public List<Integer> spiralOrder(int[][] arr) {
        List<Integer> ans = new ArrayList<Integer>();
        
        int minr = 0;
        int minc = 0;
        int maxr = arr.length-1;
        int maxc = arr[0].length-1;
        
        int count = 0;
        int total = arr.length * arr[0].length;
        while (count < total) {
            //top row
            for(int i = minc; i<=maxc && count < total; i++){
                ans.add(arr[minr][i]);
                count++;
            }
            minr++;
            //right column
            for(int i = minr; i <= maxr && count < total; i++){
                ans.add(arr[i][maxc]);
                count++;
            }
            maxc--;
            //bottom row
            for(int i = maxc; i>=minc && count < total; i--){
                ans.add(arr[maxr][i]);
                count++;
            }
            maxr--;
            
            //left column;
            for(int i = maxr; i>=minr && count < total; i--){
                ans.add(arr[i][minc]);
                count++;
            }
            minc++;
        }
        
        return ans;
    }
}