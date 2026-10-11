class Solution {
public:
    bool closeStrings(string word1, string word2) {
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        int n1=word1.size();
        int n2=word2.size();
        map<char,int>ish;
        for(int i=0;i<n1;i++){
            ish[word1[i]]++;
        }
        map<char,int>kr;
        for(int i=0;i<n2;i++){
            kr[word2[i]]++;
        }
        vector<int>v;
        vector<int>v2;
        string h="";
        string i="";

        for (auto x:ish){
            v.push_back(x.second);
            h+=x.first;
            
        }
        for (auto y:kr){
            v2.push_back(y.second);
            i+=y.first;
        }
        sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());
        if(n1==n2 &&  v==v2 && h==i){
            return true;
        }else{
            return false;
        }
    }
};