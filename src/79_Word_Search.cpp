class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result =0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (result = check(board, i, j, word, 0)) return 1;
            }
        }
     return 0;   
    }
    bool check(vector<vector<char>>& board, int r, int c, string word, int i) {
        bool result;
        if (word[i] == '\0') return 1;
        if (r <0 || c<0 ||r == board.size() || c == board[0].size()) return 0;
        if (board[r][c] != word[i]) return 0;
        board[r][c] = '\0';
        result = check(board, r+1, c, word, i+1) ||check(board, r, c+1, word, i+1) ||check(board, r, c-1, word, i+1) ||check(board, r-1, c, word, i+1); 
        //Here can not directly return. *(1) Explained below
        board[r][c] = word[i];
        return result;
    }
};
/*
*(1), if the result is false, we need to change the board[r][c] back to the original value, while is board[r][c] = word[i], 
if result is directly returned, the check function is returned, then the step board[r][c] = word[i] will not be proceeded. 
It is fine if result is true, but if the result is false, board[r][c] could not be changed back, which causes error. 
*/