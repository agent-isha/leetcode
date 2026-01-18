class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<int>s1;
        s1.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!s1.empty() && s[i]==s1.top()){
                s1.push(s[i]);
            }else if(s1.empty()){
                s1.push(s[i]);
                
            }else{
                s1.pop();
            }

        }
        vector<int>v;
        while(!s1.empty()){
            v.push_back(s1.top());
            s1.pop();
        }
        return v.size();


        
    }
};