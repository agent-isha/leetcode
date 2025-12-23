class Solution {
public:
    void solve(vector<int> op,vector<int>ip,int k,int n,vector<vector<int>>&ans){
        if(n==0&& k==0){
            ans.push_back(op);
            return;
        }
        if(n<0||k<0||ip.empty()){
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        int a=ip[0];
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(op1,ip,k-1,n-a,ans);
        solve(op2,ip,k,n,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ip={1,2,3,4,5,6,7,8,9};
        vector<int>op;
        vector<vector<int>>ans;
        solve(op,ip,k,n,ans);
        return ans;

        
    }
};