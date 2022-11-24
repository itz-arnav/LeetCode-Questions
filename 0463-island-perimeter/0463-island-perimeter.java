class Solution {
    public static int dfs (int[][] arr, int r, int c) {
        if (r >= arr.length || c >= arr[0].length || r < 0 || c < 0 || arr[r][c] == 0) {
            return 1;
        }
        if (arr[r][c] == -1) {
            return 0;
        }
        arr[r][c] = -1;

        return dfs(arr, r + 1, c) + dfs(arr, r, c + 1) + dfs(arr, r - 1, c) + dfs(arr, r, c - 1);
    }
    public int islandPerimeter(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (arr[i][j] == 1) {
                    return dfs(arr, i, j);
                }
            }
        }
        return -1;
    }
}