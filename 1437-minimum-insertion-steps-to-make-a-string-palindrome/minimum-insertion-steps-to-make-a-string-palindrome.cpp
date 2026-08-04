class Solution {
public:
    int f(int idx1,int idx2,string &s,string &s1,vector<vector<int>>&dp){
        if(idx1<0||idx2<0)return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==s1[idx2]){
            return dp[idx1][idx2]=1+f(idx1-1,idx2-1,s,s1,dp);
        }else{
            return dp[idx1][idx2]=max(f(idx1-1,idx2,s,s1,dp),f(idx1,idx2-1,s,s1,dp));
            
            

        }
        

    }
    int minInsertions(string s) {
        int n=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-(f(n-1,n-1,s,s1,dp));
        
        
    }
};