class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1){
            return ans;
        }
        ans.push_back({1,1});
        if(numRows==2){
            return ans;
        }
        int a=1;
        while(a<numRows-1){
            vector<int>v;
            v.push_back(1);
            for(int i=0;i<ans[a].size()-1;i++){
                int b=ans[a][i]+ans[a][i+1];
                v.push_back(b);


            }
            v.push_back(1);
            ans.push_back(v);
            a++;

        }
        


        return ans;
        
    }
};