class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int n=s.size();
        string t;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(!t.empty()){
                    v.push_back(t);
                    t.clear();

                }
                
            }else{
                t+=s[i];
                
            }
            

        }
        if(!t.empty()){
            v.push_back(t);
        }
        string ans;
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            if(i>0){
                ans+=' ';

            }
            
        }

        return ans;

        
    }
};