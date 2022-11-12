class Solution {
    public int nthUglyNumber(int n) {
        int[] arr = new int[n];
        int[] indexes = new int[3];
        int i = 1;
        arr[0] = 1;
        while(i < n){
            int current_element = Math.min(arr[indexes[0]]*2, Math.min(arr[indexes[1]]*3,                         arr[indexes[2]]*5));
            arr[i] = current_element;
            if(current_element == arr[indexes[0]]*2)
                indexes[0]++;
            if(current_element == arr[indexes[1]]*3)
                indexes[1]++;
            if(current_element == arr[indexes[2]]*5)
                indexes[2]++;
            
            i++;
        }
        return arr[n-1];
    }
}