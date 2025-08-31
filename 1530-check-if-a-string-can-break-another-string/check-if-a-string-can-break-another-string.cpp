class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool brea=false;
        int a=0;
        int b=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i]){
                a+=1;
                break;
            }
        }
        for(int i=0;i<s1.size();i++){
            if(s2[i]<s1[i]){
                b+=1;
                break;
            }
        }
        if(a==0||b==0){
            brea=true;
        }else{
            brea=false;
        }
        if(brea){
            return true;
        }else{
            return false;
        }


        
    }
};