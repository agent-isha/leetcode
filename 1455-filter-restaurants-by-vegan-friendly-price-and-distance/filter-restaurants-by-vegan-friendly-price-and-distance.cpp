class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int v, int mp, int md) {
        vector<pair<int,int>>isha;
        vector<int>v1;
        if(v==0){
            
            for(int i=0;i<r.size();i++){
                
                if(r[i][3]<=mp && r[i][4]<=md){
                    isha.push_back({r[i][1],r[i][0]});



                

                }
            }
        }
        if(v==1){
            
            for(int i=0;i<r.size();i++){
                
                if(r[i][2]==1 && r[i][3]<=mp && r[i][4]<=md){
                    isha.push_back({r[i][1],r[i][0]});



                

                }
            }
        }
        sort(isha.rbegin(),isha.rend());
        for(int i=0;i<isha.size();i++){
            v1.push_back(isha[i].second);

        }
        return v1;

    

        
    }
};