class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board,
               string& word, int k) {

       
        if (k == word.size()) {
            return true;
        }

        
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        
        if (board[i][j] != word[k]) {
            return false;
        }

        
        char temp = board[i][j];

        
        board[i][j] = '#';

        
        bool found =
            solve(i + 1, j, board, word, k + 1) ||  
            solve(i - 1, j, board, word, k + 1) ||  
            solve(i, j + 1, board, word, k + 1) ||  
            solve(i, j - 1, board, word, k + 1);    

       
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {

                    if (solve(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};