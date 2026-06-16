class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> visited(n, vector<int>(n,0));

        q.push({{0,0},1});
        visited[0][0] = 1;

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            if(r == n-1 && c == n-1)
                return dist;

            for(int i=0;i<8;i++){

                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   grid[nr][nc]==0 &&
                   !visited[nr][nc]){

                    visited[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }

        return -1;
    }
};