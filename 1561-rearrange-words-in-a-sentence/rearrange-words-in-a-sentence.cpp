class Solution {
public:
    string arrangeWords(string text) {
         vector<string> v;
        stringstream ss(text);
        string word;
        while(ss>> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            v.push_back(word);
        }
        map<int,vector<string>>isha;
        for(int i=0;i<v.size();i++){
            isha[v[i].size()].push_back(v[i]);

        }
        string s="";
        for(auto & a:isha){
            for(int i=0;i<a.second.size();i++){
                s+=a.second[i];
                s+=" ";
            }
        }
        s[0]=toupper(s[0]);
        s.pop_back();
        return s;
        
        
    }
};