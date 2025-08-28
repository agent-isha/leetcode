class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int a=grid.size();
        int b=grid[0].size();
        unordered_map<int,vector<int>>isha;
        unordered_map<int,vector<int>>isha1;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i-j)>=0){
                    isha[i-j].push_back(grid[i][j]);
                }

            }
        }
        for(auto & a:isha){
            sort(a.second.begin(),a.second.end());
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i-j)>=0){
                    grid[i][j]=isha[i-j].back();
                    isha[i-j].pop_back();
                }

            }
        }
       
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i-j)<0){
                    isha1[i-j].push_back(grid[i][j]);
                }

            }
        }
        for(auto & a:isha1){
            sort(a.second.rbegin(),a.second.rend());
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i-j)<0){
                
                    grid[i][j]=isha1[i-j].back();
                    isha1[i-j].pop_back();
                }

            }
        }
        return grid;

        

        
    }
};