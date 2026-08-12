class Solution {
public:
    bool f(bool ans,int idx1,int idx2,string &s,string &p,vector<vector<int>>&dp){
        if(idx1 < 0 && idx2 < 0) return true;

        if(idx2 < 0) return false;

        if(idx1 < 0) {
            for(int k = 0; k <= idx2; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        
        if(s[idx1]==p[idx2]){
            return dp[idx1][idx2]=f(ans,idx1-1,idx2-1,s,p,dp);
        }else if(p[idx2]=='?'){
            return dp[idx1][idx2]=f(ans,idx1-1,idx2-1,s,p,dp);
        }else if(p[idx2]=='*'){
            return dp[idx1][idx2]=f(ans,idx1-1,idx2,s,p,dp)||f(ans,idx1,idx2-1,s,p,dp);
            
        }
        return dp[idx1][idx2] = false;
        

    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(false,m-1,n-1,s,p,dp);
        
    }
};