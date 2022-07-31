class Solution {
public:
    int maximum69Number (int num) {
        return stoi(to_string(num).replace(to_string(num).find('6')!=string::npos?to_string(num).find('6'):0,1,"9"));
    }
};