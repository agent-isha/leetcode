class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        int rindex=0;
        for(int i=0;i<=k-1;i++){
            lsum=lsum+cp[i];
            maxsum=lsum;
            rindex=cp.size()-1;
        }
        for(int i=k-1;i>=0;i-- ){
            lsum=lsum-cp[i];
            rsum=rsum+cp[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
        
    }
};