class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

       
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = 1;
            }

            if (board[n - 1][j] == 'O' && !visited[n - 1][j]) {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = 1;
            }

            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !visited[nr][nc] &&
                    board[nr][nc] == 'O') {

                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};