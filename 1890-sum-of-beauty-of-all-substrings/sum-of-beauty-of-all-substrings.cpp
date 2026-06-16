class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        map<char,int>freq;
        for(int i=0;i<s.size();i++){
            
            freq.clear();

            for(int j=i;j<s.size();j++){
                int maxi=0;
                int mini=INT_MAX;
                freq[s[j]]++;
                for(auto x:freq){
                    if(x.second>maxi){
                        maxi=x.second;
                    }
                    if(x.second<mini){
                        mini=x.second;

                    }

                }
                sum+=maxi-mini;

            }
            
        }
        return sum;
        
        
        

        
    }
};