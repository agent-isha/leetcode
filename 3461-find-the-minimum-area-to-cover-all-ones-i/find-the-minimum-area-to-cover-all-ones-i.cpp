class Solution {
public:
    int minimumArea(vector<vector<int>>& g) {
        vector<int> v;
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        for(int i=0;i<g.size();++i){
            for(int j=0;j<g[0].size();++j){
                if(g[i][j]==1){
                    v.push_back(j);
                    break;
                }
            }
            for(int j=g[0].size()-1;j>=0;--j){
                if(g[i][j]==1){
                    v1.push_back(j);
                    break;
                }
            }
        }
        for(int i=0;i<g[0].size();++i){
            for(int j=0;j<g.size();++j){
                if(g[j][i]==1){
                    v2.push_back(j);
                    break;
                }
            }
            for(int j=g.size()-1;j>=0;--j){
                if(g[j][i]==1){
                    v3.push_back(j);
                    break;
                }
            }
        }
        int min1=*min_element(v.begin(),v.end());
        int min2=*min_element(v2.begin(),v2.end());
        int max1=*max_element(v1.begin(),v1.end());
        int max2=*max_element(v3.begin(),v3.end());
        return (max1-min1+1)*(max2-min2+1);




        
        
    }
};