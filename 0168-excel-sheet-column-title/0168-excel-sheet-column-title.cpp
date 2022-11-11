class Solution {
public:
    string convertToTitle(int columnNumber) {
    string ans = "";
    char tmp;
    while(columnNumber){
        columnNumber--;
        tmp = 'A' + columnNumber % 26;
        ans = tmp + ans;
        columnNumber /= 26;
    }
    return ans; 
}
};