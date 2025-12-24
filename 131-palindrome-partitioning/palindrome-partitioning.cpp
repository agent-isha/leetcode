class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(vector<string>op,string ip,int size,vector<vector<string>>&ans){
        if(ip.empty()){
            ans.push_back(op);
            return;
        }
        if (size > ip.length()) return;
        string c=ip.substr(0,size);
        vector<string>op1=op;
        vector<string>op2=op;
        string ip1=ip;
        string ip2=ip;
        if (isPalindrome(c)) {
            op1.push_back(c);
            ip1.erase(ip1.begin(), ip1.begin() + size);
            solve(op1, ip1, 1, ans);
        }
        solve(op2,ip2,size+1,ans);

    }
    vector<vector<string>> partition(string s) {
        string ip=s;
        vector<string>op;
        
        int size=1;
        


        vector<vector<string>>ans;
        solve(op,ip,size,ans);
        return ans;
        
    }
};