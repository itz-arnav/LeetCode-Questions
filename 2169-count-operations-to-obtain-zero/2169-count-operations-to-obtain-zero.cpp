class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 or num2 == 0)
            return 0;
        else if(num1 > num2)
            return 1 + countOperations(num2, num1-num2);
        else
            return 1 + countOperations(num1, num2 - num1);
    }
};