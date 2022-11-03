class Solution {
    public int minMutation(String start, String end, String[] bank) {
        int result = search(start, end, bank, 0);
        return result;
    }
    public int search(String start, String end, String[] bank, int count) {
        if(start.equals(end)) return count;
        if (bank.length == 0) return -1;
        int differences = 0;
        String[] newBank = new String[bank.length - 1];
        int newBankSize;
        int min = -1;
        int bestOf;

        for(int i = 0; i < bank.length; i++) {
            differences = 0;
            newBankSize = 0;
            for(int j = 0; j < 8; j++) {
                if (start.charAt(j) != bank[i].charAt(j)) differences++;
            }
            if (differences > 1) continue;
            
            for(int j = 0; j < bank.length; j++) {
                if (j != i) {
                    newBank[newBankSize] = bank[j];
                    newBankSize++;
                }
            }
            bestOf = search(bank[i], end, newBank, count+1);
            if ((bestOf != -1) && ((min == -1) || (bestOf < min))) {
                min = bestOf;
            }
        }
        return min;
    }
}