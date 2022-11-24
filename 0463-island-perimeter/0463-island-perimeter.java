class Solution {
    public static int dfs (int[][] arr, int row, int col) {
        if (row >= arr.length || col >= arr[0].length || row < 0 || col < 0 || arr[row][col] == 0) {
            return 1;
        }
        if (arr[row][col] == -1) {
            return 0;
        }
        arr[row][col] = -1;

        return dfs(arr, row + 1, col) + dfs(arr, row, col + 1) + dfs(arr, row - 1, col) + dfs(arr, row, col - 1);
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