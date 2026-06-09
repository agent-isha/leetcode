class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startcol=image[sr][sc];

        vector<vector<int>> visited(m, vector<int>(n));

        queue<pair<int,int>> q;
        
        image[sr][sc]=color;


        
        q.push({sr, sc});
        
        
        visited[sr][sc] = 2;

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row >= 0 && row < m &&
                   col >= 0 && col < n &&
                   visited[row][col] != 2 &&
                   image[row][col] == startcol){

                    image[row][col] = color;
                    q.push({row, col});
                    visited[row][col] = 2;
                }
                
            }
        }

        return image;
    }
};