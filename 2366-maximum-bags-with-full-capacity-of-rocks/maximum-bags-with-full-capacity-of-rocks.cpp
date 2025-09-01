class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        
        vector<int>v;
        if(c.size()==1){
            if(c[0]<=r[0]+a){
                return 1;
            }else{
                return 0;
            }
        }
        for(int i=0;i<c.size();i++){
            v.push_back(c[i]-r[i]);
        }
        int b;
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            
            if(sum<=a){
                b=i;
            }
        }
        return b+1;
    }
};