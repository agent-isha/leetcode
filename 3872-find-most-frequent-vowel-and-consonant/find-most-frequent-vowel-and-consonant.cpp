class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>freq;
        
        int maxi=0;
        int maxi2=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            
        }
        for(auto & a:freq){
            if(a.first=='a'||a.first=='e'||a.first=='i'||a.first=='o'||a.first=='u'){
                maxi=max(maxi,a.second);
            }
            if(a.first!='a'&& a.first!='e'&&a.first!='i'&&a.first!='o'&&a.first!='u'){
                maxi2=max(maxi2,a.second);
            }
        }
        return maxi+maxi2;
        
    }
};