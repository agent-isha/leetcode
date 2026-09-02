class Solution {
public:
    void solve(unordered_map<int,string>&m,string digits,string op,vector<string>&ans){
        if(digits.size()==0){
            ans.push_back(op);
            return;
        }
        int present=digits[0]-'0';
        digits.erase(0,1);
        string a=m[present];
        if(present!=7 && present!=9){
            string op1=op;
            string op2=op;
            string op3=op;
            op1+=a[0];
            solve(m,digits,op1,ans);
            op2+=a[1];
            solve(m,digits,op2,ans);
            op3+=a[2];
            solve(m,digits,op3,ans);

        }else{
            string op1=op;
            string op2=op;
            string op3=op;
            string op4=op;
            op1+=a[0];
            solve(m,digits,op1,ans);
            op2+=a[1];
            solve(m,digits,op2,ans);
            op3+=a[2];
            solve(m,digits,op3,ans);
            op4+=a[3];
            solve(m,digits,op4,ans);

        }


    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string>ans;
        string op;
        solve(m,digits,op,ans);
        return ans;

        
    }
};