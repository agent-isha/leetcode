class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int b;
        int sum=0;

        bool itis=true;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        if(v.size()%2==0){
            b=v.size()/2;

        }else{
            b=(v.size()/2);
        }
        if(v.size()==1){
            return 0;
        }
        
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]%x!=v[i+1]%x){
               itis=false;
            }
        }
        if(itis){
            for(int i=0;i<v.size();i++){
                sum+=abs((v[b]-v[i])/x);
            }
            return sum;




        }else{
            return -1;
        }

        
    }
};