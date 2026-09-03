class Solution {
public:

    void solve(int row, string arrange, int n,
               vector<vector<string>>& ans) {

        // All rows completed
        if (row == n) {

            vector<string> temp;

            for (int i = 0; i < n; i++) {
                temp.push_back(arrange.substr(i * n, n));
            }

            ans.push_back(temp);
            return;
        }

        // Try every column in this row
        for (int col = 0; col < n; col++) {

            int idx = row * n + col;

            // Already blocked
            if (arrange[idx] == '.')
                continue;

            string arrange2 = arrange;

            // Put queen
            arrange2[idx] = 'Q';

            // Mark row
            for (int j = 0; j < n; j++) {
                int x = row * n + j;

                if (arrange2[x] != 'Q')
                    arrange2[x] = '.';
            }

            // Mark column
            for (int i = 0; i < n; i++) {
                int x = i * n + col;

                if (arrange2[x] != 'Q')
                    arrange2[x] = '.';
            }

            // Mark diagonals
            for (int i = 0; i < n * n; i++) {

                int r = i / n;
                int c = i % n;

                if (abs(r - row) == abs(c - col)) {

                    if (arrange2[i] != 'Q')
                        arrange2[i] = '.';
                }
            }

            solve(row + 1, arrange2, n, ans);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        string arrange(n * n, '_');

        solve(0, arrange, n, ans);

        return ans;
    }
};