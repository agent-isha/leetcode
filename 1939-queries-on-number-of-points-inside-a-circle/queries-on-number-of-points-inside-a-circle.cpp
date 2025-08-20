class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& q) {
        vector<int>v;
        for(int i=0;i<q.size();i++){
            int ct=0;
            for(int j=0;j<points.size();j++){
                if(pow(points[j][0]-q[i][0],2)+pow(points[j][1]-q[i][1],2)<=pow(q[i][2],2)){
                    ct++;
                }

            }
            v.push_back(ct);
        }
        return v;

        
    }
};