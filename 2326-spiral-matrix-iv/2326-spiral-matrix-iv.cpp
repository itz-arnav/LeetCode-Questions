
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int i = 0, j = 0;
        vector<vector<int>> arr(n, vector<int>(m,-1));
        while(head != 0){
            //right
            while(j < m and arr[i][j] == -1 and head)
            {
                arr[i][j] = head->val;
                head = head->next;
                j++;
            }
            j--;
            i++;
            //bot
            while(i < n and arr[i][j] == -1 and head){
                arr[i][j] = head->val;
                head = head->next;
                i++;
            }
            i--;
            j--;
            //left
            while(j >=0 and arr[i][j] == -1 and head)
            {
                arr[i][j] = head->val;
                head = head->next;
                j--;
            }
            j++;
            i--;
            //top
            while(i >=0 and arr[i][j] == -1 and head){
                arr[i][j] = head->val;
                head = head->next;
                i--;
            }
            i++;
            j++;
        }
        return arr;
    }
};