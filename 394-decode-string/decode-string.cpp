class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != ']') {
                st.push(c);
            } 
            else {
                string rep = "";

                // Extract substring until '['
                while (!st.empty() && st.top() != '[') {
                    rep = st.top() + rep;
                    st.pop();
                }

                st.pop(); // Remove '['

                // Extract the repetition number
                int no = 0;
                int place = 1;

                while (!st.empty() && isdigit(st.top())) {
                    no += (st.top() - '0') * place;
                    place *= 10;
                    st.pop();
                }

                // Repeat the substring
                string temp = rep;

                while (no > 1) {
                    rep += temp;
                    no--;
                }

                // Push expanded string back onto stack
                for (char x : rep) {
                    st.push(x);
                }
            }
        }

        
        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};