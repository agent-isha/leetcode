class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<int>onerow;
        vector<int>onecol;
        vector<int>zerorow;
        vector<int>zerocol;
        for(int i=0;i<grid.size();i++){
            int count=0;
            int countb=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
                if(grid[i][j]==0){
                    countb++;
                }


                
            }
            onerow.push_back(count);
            zerorow.push_back(countb);
        }
        for(int i=0;i<grid[0].size();i++){
            int count=0;
            int countb=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    count++;
                }
                if(grid[j][i]==0){
                    countb++;
                }


                
            }
            onecol.push_back(count);
            zerocol.push_back(countb);
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=onerow[i]+onecol[j]-zerorow[i]-zerocol[j];
            }
        }
        return grid;
        
    }
};