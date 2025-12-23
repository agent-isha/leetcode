class Solution {
public:
    int myAtoi(string s) {
        string a = "";
        bool signTaken = false;

        for (int i = 0; i < s.size(); i++) {

            
            if (s[i] == ' ' && a.empty()) continue;

            
            if ((s[i] == '+' || s[i] == '-') && a.empty()) {
                a += s[i];
                signTaken = true;
                continue;
            }

            if (isdigit(s[i])) {
                a += s[i];
                continue;
            }

            
            break;
        }

        
        int idx = 0;
        while (idx < a.size() && a[idx] == '0') idx++;

        a = a.substr(idx);

        if (a.empty() || a == "+" || a == "-") {
            return 0;
        }

        
        try {
            return stoi(a);
        } catch (...) {
            return (a[0] == '-') ? INT_MIN : INT_MAX;
        }
    }
};
