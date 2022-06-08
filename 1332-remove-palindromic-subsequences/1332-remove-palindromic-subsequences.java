class Solution {
    public int removePalindromeSub(String s) {
        if (s.length() == 0) return 0;
        if (isPalindrome(s)) return 1;
        else return 2;
    }
            
    boolean isPalindrome(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        for (int i = 0; i < n / 2; i++) {
            if (cs[i] != cs[n-1-i]) {
                // System.out.println(s + " is not a palindrome");
                return false;
                
            }
        }
        return true;
    }
}