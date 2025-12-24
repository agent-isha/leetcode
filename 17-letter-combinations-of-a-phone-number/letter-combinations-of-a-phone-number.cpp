class Solution {
public:
    void solve(string op,string ip,unordered_map<char,string>&mp,vector<string>&ans){
        if(ip.empty()){
            ans.push_back(op);
            return;
        }
        char a=ip[0];
        string b=mp[a];
        if(b.size()==3){
            string op1=op;
            string op2=op;
            string op3=op;
            op1+=b[0];
            op2+=b[1];
            op3+=b[2];
            ip.erase(ip.begin()+0);
            solve(op1,ip,mp,ans);
            solve(op2,ip,mp,ans);
            solve(op3,ip,mp,ans);

        }else{
            string op1=op;
            string op2=op;
            string op3=op;
            string op4=op;
            op1+=b[0];
            op2+=b[1];
            op3+=b[2];
            op4+=b[3];
            ip.erase(ip.begin()+0);
            solve(op1,ip,mp,ans);
            solve(op2,ip,mp,ans);
            solve(op3,ip,mp,ans);
            solve(op4,ip,mp,ans);


        }
        
    }
    vector<string> letterCombinations(string digits) {
        string ip=digits;
        vector<string>ans;
        string op;
        unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
        };
        solve(op,ip,mp,ans);
        return ans;


        
    }
};