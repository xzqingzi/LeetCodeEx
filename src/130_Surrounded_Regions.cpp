class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <=2 || board[0].size() <= 2 ) return;
        int row = board.size();
        int col = board[0].size();
        for (int j=0; j<col; j++) {
            check(board, 0, j);
        }
        for (int i=1; i<row; i++) {
            check(board, i, 0);
        }
        for (int j=1; j<col; j++) {
            check(board, row-1, j);
        }
        for (int i=1; i<row-1; i++) {
            check(board, i, col-1);
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                board[i][j] = (board[i][j] == '1')? 'O' : 'X';
            }
        }
        return;
    }
    void check(vector<vector<char>>& board, int r, int c) {
        if (board[r][c] != 'O') return;
        board[r][c] = '1';
        if (r>1) check(board, r-1, c); // here if r>1, then search r-1>0 region, no need to search boundary. 
        if (c>1) check(board, r, c-1);
        // Can not use r>0 and c>0, may search too deeper and cause runtime error (Stack overflow) - see Discussion for detailed explanation
        //https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms
        //Since we alreay defined to search each boundary pixel in the main function, it is fine to only check the inner regions.
        //But still looks Tricky :( 
        if (r<board.size()-1) check(board, r+1, c);
        if (r<board[0].size()-1) check(board, r, c+1);
        return;
    }
};