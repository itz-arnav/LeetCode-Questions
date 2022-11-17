class Solution {
    public int[][] diagonalSort(int[][] arr) {
        int n = arr.length, m = arr[0].length;
        HashMap<Integer, PriorityQueue<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(!mp.containsKey(i - j)){
                    mp.put(i - j, new PriorityQueue<>());
                }
                mp.get(i - j).add(arr[i][j]);
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                arr[i][j] = mp.get(i - j).poll();
        return arr;
    }
}