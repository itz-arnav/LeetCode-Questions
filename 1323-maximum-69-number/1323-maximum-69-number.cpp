class Solution {
public:
    int maximum69Number (int num) {
        int temp = num, leftmost_six=-1;
    for(int i=1; temp > 0; i *= 10, temp /= 10 )
         if( temp%10 == 6 ) leftmost_six = i;
    return ( leftmost_six == -1 ? num : num + 3 * leftmost_six );
    }
};