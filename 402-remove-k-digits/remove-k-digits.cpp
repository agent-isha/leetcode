class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>s;
        if(num.size()==1 && k==1){
            return "0";

        }
        for(int i=0;i<n;i++){
            
            while(!s.empty() && s.top()-'0'>num[i]-'0' && k>0){
                s.pop();

                k--;
                

            }
            s.push(num[i]);


        }
        while(k > 0){
            s.pop();
            k--;
        }
        
        string ans;
        while(!s.empty()){

            char a=s.top();
            s.pop();            
            ans+=a;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            
            if(ans[i]-'0'!=0){
                ans.erase(0,i);
                
                break;

            }

        }
        if(ans.empty() || ans.find_first_not_of('0') == string::npos){
            return "0";
        }
        
        return ans;
        
        
        
    }
};